<?php
require_once '../src/controllers.php';

ob_start();
$title = "Арендаторы";

// Handle form submissions
if ($_POST) {
    if (isset($_POST['add_tenant'])) {
        $last_name = $_POST['last_name'];
        addTenantController($last_name);
        header("Location: tenants.php");
        exit();
    } elseif (isset($_POST['delete_tenant'])) {
        $id = $_POST['id'];
        deleteTenantController($id);
        header("Location: tenants.php");
        exit();
    }
}

$tenants = listTenants();
$content = '
<div class="tenants-section">
    <h2>Список арендаторов</h2>
    
    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Фамилия</th>
                <th>Действия</th>
            </tr>
        </thead>
        <tbody>
';

foreach ($tenants as $tenant) {
    $content .= '
            <tr>
                <td>' . $tenant['tenant_id'] . '</td>
                <td>' . htmlspecialchars($tenant['last_name']) . '</td>
                <td>
                    <form method="post" style="display:inline;" onsubmit="return confirm(\'Вы уверены, что хотите удалить этого арендатора?\')">
                        <input type="hidden" name="id" value="' . $tenant['tenant_id'] . '">
                        <button type="submit" name="delete_tenant" class="btn btn-danger">Удалить</button>
                    </form>
                </td>
            </tr>
    ';
}

$content .= '
        </tbody>
    </table>
    
    <div class="form-section">
        <h3>Добавить нового арендатора</h3>
        <form method="post">
            <div class="form-group">
                <label for="last_name">Фамилия:</label>
                <input type="text" id="last_name" name="last_name" required>
            </div>
            <button type="submit" name="add_tenant" class="btn">Добавить арендатора</button>
        </form>
    </div>
</div>
';

require_once '../src/views/layout.php';
ob_end_flush();
?>