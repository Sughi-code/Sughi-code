<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');

/**
 * Модель человека для базы данных переписи
 */
class PersonModel
{
    /**
     * Конструктор модели человека
     * @param int|null $id Идентификатор записи
     * @param string|null $fullName Полное имя
     * @param float|null $weight Вес в кг
     * @param float|null $height Рост в см
     * @param string|null $birthDate Дата рождения
     * @param string|null $gender Пол (male/female)
     * @param string|null $birthPlace Место рождения
     * @param int|null $ageGroupId Идентификатор возрастной группы
     * @param string|null $createdAt Дата создания записи
     * @param string|null $updatedAt Дата обновления записи
     */
    public function __construct(
        public ?int $id = null,
        public ?string $full_name = null,
        public ?float $weight = null,
        public ?float $height = null,
        public ?string $birth_date = null,
        public ?string $gender = null,
        public ?string $birth_place = null,
        public ?int $age_group_id = null,
        public ?string $created_at = null,
        public ?string $updated_at = null
    ) {}
    
    /**
     * Создание объекта из массива данных
     * @param array $data Массив данных
     * @return self Экземпляр класса
     */
    public static function fromArray(array $data): self
    {
        return new self(
            id: $data['id'] ?? null,
            full_name: $data['full_name'] ?? null,
            weight: isset($data['weight']) ? (float)$data['weight'] : null,
            height: isset($data['height']) ? (float)$data['height'] : null,
            birth_date: $data['birth_date'] ?? null,
            gender: $data['gender'] ?? null,
            birth_place: $data['birth_place'] ?? null,
            age_group_id: isset($data['age_group_id']) ? (int)$data['age_group_id'] : null,
            created_at: $data['created_at'] ?? null,
            updated_at: $data['updated_at'] ?? null
        );
    }
}

/**
 * Модель возрастной группы
 */
class AgeGroupModel
{
    /**
     * Конструктор модели возрастной группы
     * @param int|null $id Идентификатор группы
     * @param string|null $name Название группы
     * @param int|null $minAge Минимальный возраст
     * @param int|null $maxAge Максимальный возраст
     */
    public function __construct(
        public ?int $id = null,
        public ?string $name = null,
        public ?int $min_age = null,
        public ?int $max_age = null
    ) {}
}

/**
 * Репозиторий для работы с данными о людях
 */
class PersonRepository
{
    /**
     * Конструктор репозитория
     * @param PDO $db Объект соединения с базой данных
     */
    public function __construct(private PDO $db) {}
    
    /**
     * Получение всех записей о людях
     * @return array Массив записей
     */
    public function getAll(): array
    {
        $stmt = $this->db->prepare("
            SELECT p.*, ag.name as age_group_name 
            FROM people p
            JOIN age_groups ag ON p.age_group_id = ag.id
            ORDER BY p.full_name
        ");
        $stmt->execute();
        return $stmt->fetchAll();
    }
    
    /**
     * Получение записи по идентификатору
     * @param int $id Идентификатор записи
     * @return array|null Данные записи или null
     */
    public function getById(int $id): ?array
    {
        $stmt = $this->db->prepare("
            SELECT p.*, ag.name as age_group_name 
            FROM people p
            JOIN age_groups ag ON p.age_group_id = ag.id
            WHERE p.id = :id
        ");
        $stmt->bindValue(':id', $id, PDO::PARAM_INT);
        $stmt->execute();
        return $stmt->fetch() ?: null;
    }
    
    /**
     * Создание новой записи
     * @param array $data Данные для создания
     * @return int Идентификатор созданной записи
     */
    public function create(array $data): int
    {
        $stmt = $this->db->prepare("
            INSERT INTO people (
                full_name, weight, height, birth_date, gender, 
                birth_place, age_group_id
            ) VALUES (
                :full_name, :weight, :height, :birth_date, :gender, 
                :birth_place, :age_group_id
            )
        ");
        
        $stmt->bindValue(':full_name', $data['full_name']);
        $stmt->bindValue(':weight', $data['weight'], PDO::PARAM_STR);
        $stmt->bindValue(':height', $data['height'], PDO::PARAM_STR);
        $stmt->bindValue(':birth_date', $data['birth_date']);
        $stmt->bindValue(':gender', $data['gender']);
        $stmt->bindValue(':birth_place', $data['birth_place']);
        $stmt->bindValue(':age_group_id', $data['age_group_id'], PDO::PARAM_INT);
        
        $stmt->execute();
        return $this->db->lastInsertId();
    }
    
    /**
     * Удаление записи
     * @param int $id Идентификатор записи
     * @return bool Результат операции
     */
    public function delete(int $id): bool
    {
        $stmt = $this->db->prepare("DELETE FROM people WHERE id = :id");
        $stmt->bindValue(':id', $id, PDO::PARAM_INT);
        return $stmt->execute() && $stmt->rowCount() > 0;
    }
    
    /**
     * Получение всех возрастных групп
     * @return array Массив групп
     */
    public function getAgeGroups(): array
    {
        $stmt = $this->db->prepare("SELECT * FROM age_groups ORDER BY min_age");
        $stmt->execute();
        return $stmt->fetchAll();
    }
    
    /**
     * Подсчет людей старше указанного возраста
     * @param int $age Возраст для сравнения
     * @return int Количество людей
     */
    public function countPeopleOlderThan(int $age): int
    {
        $stmt = $this->db->prepare("
            SELECT COUNT(*) as count 
            FROM people 
            WHERE TIMESTAMPDIFF(YEAR, birth_date, CURDATE()) > :age
        ");
        $stmt->bindValue(':age', $age, PDO::PARAM_INT);
        $stmt->execute();
        $result = $stmt->fetch();
        return (int)$result['count'];
    }
    
    /**
     * Получение статистики по средним показателям для каждого пола
     * @return array Массив статистики
     */
    public function getAverageStatsByGender(): array
    {
        $stmt = $this->db->prepare("
            SELECT 
                gender,
                AVG(height) as avg_height,
                AVG(weight) as avg_weight
            FROM people
            GROUP BY gender
        ");
        $stmt->execute();
        return $stmt->fetchAll();
    }
    
    /**
     * Получение людей с весом выше среднего по возрастным группам
     * @return array Массив статистики
     */
    public function getPeopleWithWeightAboveAverageByAgeGroup(): array
    {
        $stmt = $this->db->prepare("
            SELECT 
                ag.name as age_group,
                COUNT(*) as count_above_avg,
                (SELECT AVG(weight) FROM people p2 WHERE p2.age_group_id = p.age_group_id) as avg_weight
            FROM people p
            JOIN age_groups ag ON p.age_group_id = ag.id
            WHERE p.weight > (
                SELECT AVG(weight) 
                FROM people p2 
                WHERE p2.age_group_id = p.age_group_id
            )
            GROUP BY p.age_group_id, ag.name
        ");
        $stmt->execute();
        return $stmt->fetchAll();
    }
}
?>