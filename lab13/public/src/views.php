<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');

/**
 * Генерация HTML для главной страницы
 * @param array $people Массив данных о людях
 * @return string HTML содержимое
 */
function renderIndexView(array $people): string
{
    ob_start();
    ?>
    <h2>Список людей</h2>
    <div class="table-container">
        <table>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>ФИО</th>
                    <th>Вес (кг)</th>
                    <th>Рост (см)</th>
                    <th>Дата рождения</th>
                    <th>Возраст</th>
                    <th>Пол</th>
                    <th>Место рождения</th>
                    <th>Возрастная группа</th>
                    <th>Действия</th>
                </tr>
            </thead>
            <tbody>
                <?php foreach ($people as $person): ?>
                    <?php
                        $birthDate = new DateTime($person['birth_date']);
                        $today = new DateTime();
                        $age = $today->diff($birthDate)->y;
                    ?>
                    <tr>
                        <td><?= htmlspecialchars($person['id']) ?></td>
                        <td><?= htmlspecialchars($person['full_name']) ?></td>
                        <td><?= htmlspecialchars($person['weight']) ?></td>
                        <td><?= htmlspecialchars($person['height']) ?></td>
                        <td><?= htmlspecialchars($person['birth_date']) ?></td>
                        <td><?= $age ?></td>
                        <td><?= $person['gender'] === 'male' ? 'Мужской' : 'Женский' ?></td>
                        <td><?= htmlspecialchars($person['birth_place']) ?></td>
                        <td><?= htmlspecialchars($person['age_group_name']) ?></td>
                        <td>
                            <form method="POST" action="/delete/<?= $person['id'] ?>" style="display: inline;">
                                <button type="submit" class="btn-delete" onclick="return confirm('Вы уверены, что хотите удалить эту запись?')">Удалить</button>
                            </form>
                        </td>
                    </tr>
                <?php endforeach; ?>
            </tbody>
        </table>
    </div>
    <?php
    return ob_get_clean();
}

/**
 * Генерация HTML для формы добавления
 * @param array $ageGroups Массив возрастных групп
 * @param array $errors Массив ошибок валидации
 * @param array $formData Введенные данные формы
 * @return string HTML содержимое
 */
function renderAddView(array $ageGroups, array $errors, array $formData): string
{
    ob_start();
    ?>
    <h2>Добавить человека</h2>
    <?php if (!empty($errors)): ?>
        <div class="alert error">
            <ul>
                <?php foreach ($errors as $error): ?>
                    <li><?= htmlspecialchars($error) ?></li>
                <?php endforeach; ?>
            </ul>
        </div>
    <?php endif; ?>

    <form method="POST" action="/add">
        <div class="form-group">
            <label for="full_name">ФИО:</label>
            <input type="text" id="full_name" name="full_name" value="<?= htmlspecialchars($formData['full_name'] ?? '') ?>" required>
        </div>
        
        <div class="form-group">
            <label for="weight">Вес (кг):</label>
            <input type="number" id="weight" name="weight" step="0.01" value="<?= htmlspecialchars($formData['weight'] ?? '') ?>" required>
        </div>
        
        <div class="form-group">
            <label for="height">Рост (см):</label>
            <input type="number" id="height" name="height" step="0.01" value="<?= htmlspecialchars($formData['height'] ?? '') ?>" required>
        </div>
        
        <div class="form-group">
            <label for="birth_date">Дата рождения:</label>
            <input type="date" id="birth_date" name="birth_date" value="<?= htmlspecialchars($formData['birth_date'] ?? date('Y-m-d')) ?>" required>
        </div>
        
        <div class="form-group">
            <label>Пол:</label>
            <div class="radio-group">
                <input type="radio" id="gender_male" name="gender" value="male" <?= ($formData['gender'] ?? 'male') === 'male' ? 'checked' : '' ?> required>
                <label for="gender_male">Мужской</label>
                
                <input type="radio" id="gender_female" name="gender" value="female" <?= ($formData['gender'] ?? '') === 'female' ? 'checked' : '' ?>>
                <label for="gender_female">Женский</label>
            </div>
        </div>
        
        <div class="form-group">
            <label for="birth_place">Место рождения:</label>
            <input type="text" id="birth_place" name="birth_place" value="<?= htmlspecialchars($formData['birth_place'] ?? '') ?>" required>
        </div>
        
        <div class="form-group">
            <label for="age_group_id">Возрастная группа:</label>
            <select id="age_group_id" name="age_group_id" required>
                <option value="">Выберите группу</option>
                <?php foreach ($ageGroups as $group): ?>
                    <option value="<?= $group['id'] ?>" <?= ($formData['age_group_id'] ?? '') == $group['id'] ? 'selected' : '' ?>>
                        <?= htmlspecialchars($group['name']) ?> (<?= $group['min_age'] ?>-<?= $group['max_age'] ?> лет)
                    </option>
                <?php endforeach; ?>
            </select>
        </div>
        
        <div class="form-actions">
            <button type="submit" class="btn-primary">Добавить</button>
            <a href="/" class="btn-secondary">Отмена</a>
        </div>
    </form>
    <?php
    return ob_get_clean();
}

/**
 * Генерация HTML для подтверждения удаления
 * @param array $person Данные о человеке
 * @return string HTML содержимое
 */
function renderDeleteView(array $person): string
{
    ob_start();
    $birthDate = new DateTime($person['birth_date']);
    $today = new DateTime();
    $age = $today->diff($birthDate)->y;
    ?>
    <h2>Удаление записи</h2>
    <div class="confirmation-box">
        <p>Вы уверены, что хотите удалить следующую запись?</p>
        <div class="person-details">
            <p><strong>ФИО:</strong> <?= htmlspecialchars($person['full_name']) ?></p>
            <p><strong>Возраст:</strong> <?= $age ?> лет</p>
            <p><strong>Место рождения:</strong> <?= htmlspecialchars($person['birth_place']) ?></p>
        </div>
        
        <form method="POST" action="/delete/<?= $person['id'] ?>">
            <div class="form-actions">
                <button type="submit" class="btn-danger">Да, удалить</button>
                <a href="/" class="btn-secondary">Отмена</a>
            </div>
        </form>
    </div>
    <?php
    return ob_get_clean();
}

/**
 * Генерация HTML для отчета по возрасту
 * @param int $minAge Минимальный возраст
 * @param int $count Количество людей
 * @return string HTML содержимое
 */
function renderAgeReportView(int $minAge, int $count): string
{
    ob_start();
    ?>
    <h2>Отчет: Количество лиц, возраст которых больше указанного</h2>
    <div class="report-container">
        <form method="GET" action="/report/age" class="filter-form">
            <div class="form-group">
                <label for="min_age">Минимальный возраст:</label>
                <input type="number" id="min_age" name="min_age" value="<?= htmlspecialchars($minAge) ?>" min="0" max="120" required>
                <button type="submit" class="btn-primary">Показать</button>
            </div>
        </form>
        
        <div class="report-result">
            <h3>Результат:</h3>
            <p>Количество людей старше <?= htmlspecialchars($minAge) ?> лет: <strong><?= $count ?></strong></p>
        </div>
        
        <div class="chart-container">
            <canvas id="ageChart" width="400" height="200"></canvas>
        </div>
    </div>

    <script>
        document.addEventListener('DOMContentLoaded', function() {
            const ctx = document.getElementById('ageChart').getContext('2d');
            new Chart(ctx, {
                type: 'bar',
                 {
                    labels: ['Люди старше <?= $minAge ?> лет'],
                    datasets: [{
                        label: 'Количество человек',
                         [<?= $count ?>],
                        backgroundColor: 'rgba(75, 192, 192, 0.6)',
                        borderColor: 'rgba(75, 192, 192, 1)',
                        borderWidth: 1
                    }]
                },
                options: {
                    scales: {
                        y: {
                            beginAtZero: true,
                            ticks: {
                                stepSize: 1
                            }
                        }
                    }
                }
            });
        });
    </script>
    <?php
    return ob_get_clean();
}

/**
 * Генерация HTML для отчета по полу
 * @param array $stats Статистика по полу
 * @return string HTML содержимое
 */
function renderGenderStatsReportView(array $stats): string
{
    ob_start();
    ?>
    <h2>Отчет: Средний рост и средний вес отдельно для мужчин и женщин</h2>
    <div class="report-container">
        <div class="report-result">
            <h3>Статистика по полу:</h3>
            <table class="report-table">
                <thead>
                    <tr>
                        <th>Пол</th>
                        <th>Средний рост (см)</th>
                        <th>Средний вес (кг)</th>
                    </tr>
                </thead>
                <tbody>
                    <?php foreach ($stats as $stat): ?>
                        <tr>
                            <td><?= $stat['gender'] === 'male' ? 'Мужской' : 'Женский' ?></td>
                            <td><?= number_format($stat['avg_height'], 2) ?></td>
                            <td><?= number_format($stat['avg_weight'], 2) ?></td>
                        </tr>
                    <?php endforeach; ?>
                </tbody>
            </table>
        </div>
        
        <div class="chart-container">
            <canvas id="genderChart" width="400" height="200"></canvas>
        </div>
    </div>

    <script>
        document.addEventListener('DOMContentLoaded', function() {
            const ctx = document.getElementById('genderChart').getContext('2d');
            
            const genders = <?= json_encode(array_map(fn($s) => $s['gender'] === 'male' ? 'Мужской' : 'Женский', $stats)) ?>;
            const avgHeights = <?= json_encode(array_map(fn($s) => $s['avg_height'], $stats)) ?>;
            const avgWeights = <?= json_encode(array_map(fn($s) => $s['avg_weight'], $stats)) ?>;
            
            new Chart(ctx, {
                type: 'bar',
                 {
                    labels: genders,
                    datasets: [
                        {
                            label: 'Средний рост (см)',
                             avgHeights,
                            backgroundColor: 'rgba(54, 162, 235, 0.6)',
                            borderColor: 'rgba(54, 162, 235, 1)',
                            borderWidth: 1
                        },
                        {
                            label: 'Средний вес (кг)',
                             avgWeights,
                            backgroundColor: 'rgba(255, 99, 132, 0.6)',
                            borderColor: 'rgba(255, 99, 132, 1)',
                            borderWidth: 1
                        }
                    ]
                },
                options: {
                    scales: {
                        y: {
                            beginAtZero: true
                        }
                    },
                    responsive: true,
                    plugins: {
                        title: {
                            display: true,
                            text: 'Средние показатели по полу'
                        }
                    }
                }
            });
        });
    </script>
    <?php
    return ob_get_clean();
}

/**
 * Генерация HTML для отчета по весу выше среднего
 * @param array $stats Статистика по возрастным группам
 * @return string HTML содержимое
 */
function renderWeightAboveAvgReportView(array $stats): string
{
    ob_start();
    ?>
    <h2>Отчет: Количество лиц, имеющих вес выше среднего по каждой возрастной группе</h2>
    <div class="report-container">
        <div class="report-result">
            <h3>Статистика по возрастным группам:</h3>
            <table class="report-table">
                <thead>
                    <tr>
                        <th>Возрастная группа</th>
                        <th>Средний вес (кг)</th>
                        <th>Количество людей с весом выше среднего</th>
                    </tr>
                </thead>
                <tbody>
                    <?php foreach ($stats as $stat): ?>
                        <tr>
                            <td><?= htmlspecialchars($stat['age_group']) ?></td>
                            <td><?= number_format($stat['avg_weight'], 2) ?></td>
                            <td><?= $stat['count_above_avg'] ?></td>
                        </tr>
                    <?php endforeach; ?>
                </tbody>
            </table>
        </div>
        
        <div class="chart-container">
            <canvas id="weightChart" width="400" height="200"></canvas>
        </div>
    </div>

    <script>
        document.addEventListener('DOMContentLoaded', function() {
            const ctx = document.getElementById('weightChart').getContext('2d');
            
            const ageGroups = <?= json_encode(array_map(fn($s) => $s['age_group'], $stats)) ?>;
            const countsAboveAvg = <?= json_encode(array_map(fn($s) => $s['count_above_avg'], $stats)) ?>;
            const avgWeights = <?= json_encode(array_map(fn($s) => $s['avg_weight'], $stats)) ?>;
            
            new Chart(ctx, {
                type: 'bar',
                 {
                    labels: ageGroups,
                    datasets: [
                        {
                            label: 'Количество людей с весом выше среднего',
                             countsAboveAvg,
                            backgroundColor: 'rgba(75, 192, 192, 0.6)',
                            borderColor: 'rgba(75, 192, 192, 1)',
                            borderWidth: 1
                        },
                        {
                            label: 'Средний вес (кг)',
                             avgWeights,
                            backgroundColor: 'rgba(153, 102, 255, 0.6)',
                            borderColor: 'rgba(153, 102, 255, 1)',
                            borderWidth: 1,
                            type: 'line',
                            yAxisID: 'y1'
                        }
                    ]
                },
                options: {
                    responsive: true,
                    scales: {
                        y: {
                            type: 'linear',
                            display: true,
                            position: 'left',
                            title: {
                                display: true,
                                text: 'Количество людей'
                            }
                        },
                        y1: {
                            type: 'linear',
                            display: true,
                            position: 'right',
                            title: {
                                display: true,
                                text: 'Средний вес (кг)'
                            },
                            grid: {
                                drawOnChartArea: false
                            }
                        }
                    },
                    plugins: {
                        title: {
                            display: true,
                            text: 'Вес выше среднего по возрастным группам'
                        }
                    }
                }
            });
        });
    </script>
    <?php
    return ob_get_clean();
}

/**
 * Генерация HTML для страницы 404
 * @param array $data Данные для страницы
 * @return string HTML содержимое
 */
function render404View(array $data): string
{
    ob_start();
    ?>
    <h1>404 - Страница не найдена</h1>
    <p><?= htmlspecialchars($data['message'] ?? 'Запрашиваемая страница не существует') ?></p>
    <p><a href="/" class="btn-primary">Вернуться на главную</a></p>
    <?php
    return ob_get_clean();
}

/**
 * Генерация полного HTML макета
 * @param string $view Название представления
 * @param array $data Данные для представления
 * @return string Полный HTML документ
 */
function renderLayout(string $view, array $data = []): string
{
    extract($data);
    ob_start();
    ?>
    <!DOCTYPE html>
    <html lang="ru">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>База данных "Перепись"</title>
        <link rel="stylesheet" href="/style.css">
        <script src="https://cdn.jsdelivr.net/npm/chart.js"></script>
    </head>
    <body>
        <div class="container">
            <header>
                <h1>База данных "Перепись"</h1>
                <nav>
                    <ul>
                        <li><a href="/">Главная</a></li>
                        <li><a href="/add">Добавить человека</a></li>
                        <li class="dropdown">
                            <a href="javascript:void(0)">Отчеты</a>
                            <div class="dropdown-content">
                                <a href="/report/age">Люди старше указанного возраста</a>
                                <a href="/report/gender-stats">Средние показатели по полу</a>
                                <a href="/report/weight-above-avg">Вес выше среднего по возрастным группам</a>
                            </div>
                        </li>
                    </ul>
                </nav>
            </header>
            
            <main>
                <?php if (isset($_GET['success'])): ?>
                    <div class="alert success">Запись успешно добавлена!</div>
                <?php endif; ?>
                
                <?php if (isset($_GET['deleted'])): ?>
                    <div class="alert success">Запись успешно удалена!</div>
                <?php endif; ?>
                
                <?php if (isset($_GET['error'])): ?>
                    <div class="alert error">
                        <?php 
                        $errorMessage = match($_GET['error']) {
                            'not_found' => 'Запись не найдена!',
                            'invalid_id' => 'Некорректный ID записи!',
                            default => 'Произошла ошибка при обработке запроса.',
                        };
                        echo htmlspecialchars($errorMessage);
                        ?>
                    </div>
                <?php endif; ?>
                
                <?php
                switch ($view) {
                    case 'index':
                        echo renderIndexView($people ?? []);
                        break;
                    case 'add':
                        echo renderAddView(
                            $ageGroups ?? [],
                            $errors ?? [],
                            $formData ?? []
                        );
                        break;
                    case 'delete':
                        echo renderDeleteView($person ?? []);
                        break;
                    case 'report_age':
                        echo renderAgeReportView($minAge ?? 18, $count ?? 0);
                        break;
                    case 'report_gender_stats':
                        echo renderGenderStatsReportView($stats ?? []);
                        break;
                    case 'report_weight_above_avg':
                        echo renderWeightAboveAvgReportView($stats ?? []);
                        break;
                    case '404':
                        echo render404View($data ?? []);
                        break;
                    default:
                        echo '<p>Страница не найдена</p>';
                }
                ?>
            </main>
            
            <footer>
                <p>&copy; <?= date('Y') ?> База данных "Перепись". Все права защищены.</p>
            </footer>
        </div>
    </body>
    </html>
    <?php
    return ob_get_clean();
}
?>