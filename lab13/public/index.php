<?php
error_reporting(E_ALL);
ini_set('display_errors', '1');

require __DIR__ . '/../vendor/autoload.php';
require __DIR__ . '/src/database.php';
require __DIR__ . '/src/models.php';
require __DIR__ . '/src/controllers.php';
require_once __DIR__ . '/src/views.php'; // Простое подключение без параметров

$controller = new CensusController($databaseConnection);

// Роутинг
$path = parse_url($_SERVER['REQUEST_URI'], PHP_URL_PATH);
$path = str_replace('/lab13/public', '', $path);
$path = trim($path, '/');

// Обработка маршрутов
if ($path === '' || $path === 'index.php') {
    $controller->index();
} elseif ($path === 'add') {
    if ($_SERVER['REQUEST_METHOD'] === 'POST') {
        $controller->addPerson();
    } else {
        $controller->showAddForm();
    }
} elseif (preg_match('#^delete/(\d+)$#', $path, $matches)) {
    $controller->deletePerson($matches[1]);
} elseif ($path === 'report/age') {
    $controller->showAgeReport();
} elseif ($path === 'report/gender-stats') {
    $controller->showGenderStatsReport();
} elseif ($path === 'report/weight-above-avg') {
    $controller->showWeightAboveAvgReport();
} else {
    http_response_code(404);
    echo '<h1>404 - Страница не найдена</h1>';
}
?>