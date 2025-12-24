<?php
require_once '../src/controllers.php';

ob_start();
$title = "Объекты недвижимости";

// Handle form submissions
if ($_POST) {
    if (isset($_POST['add_property'])) {
        $type = $_POST['type'];
        $monthly_rent = $_POST['monthly_rent'];
        addPropertyController($type, $monthly_rent);
        header("Location: properties.php");
        exit();
    } elseif (isset($_POST['delete_property'])) {
        $id = $_POST['id'];
        deletePropertyController($id);
        header("Location: properties.php");
        exit();
    }
}

$properties = listProperties();
$content = '
<div class="properties-section">
    <h2>Список объектов недвижимости</h2>
    
    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Тип</th>
                <th>Ежемесячная аренда</th>
                <th>Действия</th>
            </tr>
        </thead>
        <tbody>
';

foreach ($properties as $property) {
    $content .= '
            <tr>
                <td>' . $property['property_id'] . '</td>
                <td>' . htmlspecialchars($property['type']) . '</td>
                <td>' . number_format($property['monthly_rent'], 2) . '</td>
                <td>
                    <form method="post" style="display:inline;" onsubmit="return confirm(\'Вы уверены, что хотите удалить этот объект недвижимости?\')">
                        <input type="hidden" name="id" value="' . $property['property_id'] . '">
                        <button type="submit" name="delete_property" class="btn btn-danger">Удалить</button>
                    </form>
                </td>
            </tr>
    ';
}

$content .= '
        </tbody>
    </table>
    
    <div class="form-section">
        <h3>Добавить новый объект недвижимости</h3>
        <form method="post">
            <div class="form-group">
                <label for="type">Тип:</label>
                <input type="text" id="type" name="type" required>
            </div>
            <div class="form-group">
                <label for="monthly_rent">Ежемесячная аренда:</label>
                <input type="number" id="monthly_rent" name="monthly_rent" step="0.01" min="0" required>
            </div>
            <button type="submit" name="add_property" class="btn">Добавить объект</button>
        </form>
    </div>
</div>
';

require_once '../src/views/layout.php';
ob_end_flush();
?>