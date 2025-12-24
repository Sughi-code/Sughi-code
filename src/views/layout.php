<!DOCTYPE html>
<html lang="ru">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title><?php echo isset($title) ? $title : 'Система аренды'; ?></title>
    <link rel="stylesheet" href="/css/style.css">
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            background-color: #f5f5f5;
        }
        .container {
            max-width: 1200px;
            margin: 0 auto;
            background-color: white;
            padding: 20px;
            border-radius: 8px;
            box-shadow: 0 2px 10px rgba(0,0,0,0.1);
        }
        h1 {
            color: #333;
            border-bottom: 2px solid #007cba;
            padding-bottom: 10px;
        }
        .nav {
            margin-bottom: 20px;
        }
        .nav a {
            display: inline-block;
            padding: 10px 15px;
            margin-right: 10px;
            background-color: #007cba;
            color: white;
            text-decoration: none;
            border-radius: 4px;
        }
        .nav a:hover {
            background-color: #005a87;
        }
        table {
            width: 100%;
            border-collapse: collapse;
            margin: 20px 0;
        }
        th, td {
            border: 1px solid #ddd;
            padding: 12px;
            text-align: left;
        }
        th {
            background-color: #f2f2f2;
        }
        tr:nth-child(even) {
            background-color: #f9f9f9;
        }
        .form-group {
            margin-bottom: 15px;
        }
        .form-group label {
            display: block;
            margin-bottom: 5px;
            font-weight: bold;
        }
        .form-group input, .form-group select {
            width: 100%;
            padding: 8px;
            border: 1px solid #ddd;
            border-radius: 4px;
            box-sizing: border-box;
        }
        .btn {
            background-color: #007cba;
            color: white;
            padding: 10px 15px;
            border: none;
            border-radius: 4px;
            cursor: pointer;
        }
        .btn:hover {
            background-color: #005a87;
        }
        .btn-danger {
            background-color: #d9534f;
        }
        .btn-danger:hover {
            background-color: #c9302c;
        }
        .report-section {
            margin: 20px 0;
            padding: 15px;
            border: 1px solid #ddd;
            border-radius: 4px;
            background-color: #f9f9f9;
        }
    </style>
</head>
<body>
    <div class="container">
        <h1><?php echo isset($title) ? $title : 'Система аренды'; ?></h1>
        
        <div class="nav">
            <a href="/">Главная</a>
            <a href="/tenants.php">Арендаторы</a>
            <a href="/properties.php">Объекты недвижимости</a>
            <a href="/leases.php">Аренды</a>
            <a href="/reports.php">Отчеты</a>
        </div>
        
        <?php echo $content; ?>
    </div>
</body>
</html>