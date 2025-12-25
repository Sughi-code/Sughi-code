<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');

require_once __DIR__ . '/models.php';
require_once __DIR__ . '/views.php';

/**
 * Контроллер для работы с базой данных переписи
 */
class CensusController
{
    /**
     * Репозиторий для работы с данными
     */
    private PersonRepository $repository;
    
    /**
     * Конструктор контроллера
     * @param PDO $db Объект соединения с базой данных
     */
    public function __construct(PDO $db)
    {
        $this->repository = new PersonRepository($db);
    }
    
    /**
     * Отображение главной страницы со списком людей
     */
    public function index(): void
    {
        $people = $this->repository->getAll();
        $html = renderLayout('index', ['people' => $people]);
        echo $html;
    }
    
    /**
     * Отображение формы добавления человека
     */
    public function showAddForm(): void
    {
        $ageGroups = $this->repository->getAgeGroups();
        $html = renderLayout('add', [
            'ageGroups' => $ageGroups,
            'errors' => [],
            'formData' => []
        ]);
        echo $html;
    }
    
    /**
     * Добавление нового человека
     */
    public function addPerson(): void
    {
        $ageGroups = $this->repository->getAgeGroups();
        $errors = [];
        $formData = $_POST ?? [];
        
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            $fullName = trim($_POST['full_name'] ?? '');
            $weight = trim($_POST['weight'] ?? '');
            $height = trim($_POST['height'] ?? '');
            $birthDate = trim($_POST['birth_date'] ?? '');
            $gender = $_POST['gender'] ?? '';
            $birthPlace = trim($_POST['birth_place'] ?? '');
            $ageGroupId = $_POST['age_group_id'] ?? '';
            
            // Валидация данных
            if (empty($fullName)) $errors[] = 'ФИО обязательно для заполнения';
            if (empty($weight) || !is_numeric($weight) || (float)$weight <= 0) $errors[] = 'Вес должен быть положительным числом';
            if (empty($height) || !is_numeric($height) || (float)$height <= 0) $errors[] = 'Рост должен быть положительным числом';
            if (empty($birthDate)) $errors[] = 'Дата рождения обязательна';
            if (!in_array($gender, ['male', 'female'])) $errors[] = 'Некорректный пол';
            if (empty($birthPlace)) $errors[] = 'Место рождения обязательно';
            if (empty($ageGroupId) || !is_numeric($ageGroupId) || (int)$ageGroupId <= 0) $errors[] = 'Выберите возрастную группу';
            
            if (empty($errors)) {
                $data = [
                    'full_name' => $fullName,
                    'weight' => (float)$weight,
                    'height' => (float)$height,
                    'birth_date' => $birthDate,
                    'gender' => $gender,
                    'birth_place' => $birthPlace,
                    'age_group_id' => (int)$ageGroupId
                ];
                
                $id = $this->repository->create($data);
                header('Location: /?success=1');
                exit;
            }
        }
        
        $html = renderLayout('add', [
            'ageGroups' => $ageGroups,
            'errors' => $errors,
            'formData' => $formData
        ]);
        echo $html;
    }
    
    /**
     * Удаление человека по идентификатору
     * @param string $id Идентификатор записи
     */
    public function deletePerson(string $id): void
    {
        if (!is_numeric($id) || (int)$id <= 0) {
            header('Location: /?error=invalid_id');
            exit;
        }
        
        $personId = (int)$id;
        
        if ($_SERVER['REQUEST_METHOD'] === 'POST') {
            if ($this->repository->delete($personId)) {
                header('Location: /?deleted=1');
            } else {
                header('Location: /?error=not_found');
            }
            exit;
        }
        
        $person = $this->repository->getById($personId);
        
        if (!$person) {
            header('Location: /?error=not_found');
            exit;
        }
        
        $html = renderLayout('delete', ['person' => $person]);
        echo $html;
    }
    
    /**
     * Отображение отчета по возрасту
     */
    public function showAgeReport(): void
    {
        $minAge = isset($_GET['min_age']) && is_numeric($_GET['min_age']) && (int)$_GET['min_age'] >= 0 
            ? (int)$_GET['min_age'] 
            : 18;
        
        $count = $this->repository->countPeopleOlderThan($minAge);
        $html = renderLayout('report_age', ['minAge' => $minAge, 'count' => $count]);
        echo $html;
    }
    
    /**
     * Отображение отчета по полу
     */
    public function showGenderStatsReport(): void
    {
        $stats = $this->repository->getAverageStatsByGender();
        $html = renderLayout('report_gender_stats', ['stats' => $stats]);
        echo $html;
    }
    
    /**
     * Отображение отчета по весу выше среднего
     */
    public function showWeightAboveAvgReport(): void
    {
        $stats = $this->repository->getPeopleWithWeightAboveAverageByAgeGroup();
        $html = renderLayout('report_weight_above_avg', ['stats' => $stats]);
        echo $html;
    }
}
?>