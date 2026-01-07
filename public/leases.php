<?php
require_once '../src/controllers.php';

ob_start();
$title = "Аренды";

// Handle form submissions
if ($_POST) {
    if (isset($_POST['add_lease'])) {
        $tenant_id = $_POST['tenant_id'];
        $property_id = $_POST['property_id'];
        $start_date = $_POST['start_date'];
        $duration_months = $_POST['duration_months'];
        addLeaseController($tenant_id, $property_id, $start_date, $duration_months);
        header("Location: leases.php");
        exit();
    } elseif (isset($_POST['delete_lease'])) {
        $id = $_POST['id'];
        deleteLeaseController($id);
        header("Location: leases.php");
        exit();
    }
}

$leases = listLeases();

// Get all tenants and properties for the form
$tenants = listTenants();
$properties = listProperties();

$content = '
<div class="leases-section">
    <h2>Список аренд</h2>
    
    <table>
        <thead>
            <tr>
                <th>ID</th>
                <th>Арендатор</th>
                <th>Объект недвижимости</th>
                <th>Дата начала</th>
                <th>Продолжительность (мес.)</th>
                <th>Действия</th>
            </tr>
        </thead>
        <tbody>
';

foreach ($leases as $lease) {
    $content .= '
            <tr>
                <td>' . $lease['lease_id'] . '</td>
                <td>' . htmlspecialchars($lease['last_name']) . '</td>
                <td>' . htmlspecialchars($lease['property_type']) . '</td>
                <td>' . $lease['start_date'] . '</td>
                <td>' . $lease['duration_months'] . '</td>
                <td>
                    <form method="post" style="display:inline;" onsubmit="return confirm(\'Вы уверены, что хотите удалить эту аренду?\')">
                        <input type="hidden" name="id" value="' . $lease['lease_id'] . '">
                        <button type="submit" name="delete_lease" class="btn btn-danger">Удалить</button>
                    </form>
                </td>
            </tr>
    ';
}

$content .= '
        </tbody>
    </table>
    
    <div class="form-section">
        <h3>Добавить новую аренду</h3>
        <form method="post">
            <div class="form-group">
                <label for="tenant_id">Арендатор:</label>
                <select id="tenant_id" name="tenant_id" required>
                    <option value="">Выберите арендатора</option>
';

foreach ($tenants as $tenant) {
    $content .= '<option value="' . $tenant['tenant_id'] . '">' . htmlspecialchars($tenant['last_name']) . '</option>';
}

$content .= '
                </select>
            </div>
            <div class="form-group">
                <label for="property_id">Объект недвижимости:</label>
                <select id="property_id" name="property_id" required>
                    <option value="">Выберите объект недвижимости</option>
';

foreach ($properties as $property) {
    $content .= '<option value="' . $property['property_id'] . '">' . htmlspecialchars($property['type']) . ' (' . number_format($property['monthly_rent'], 2) . ')</option>';
}

$content .= '
                </select>
            </div>
            <div class="form-group">
                <label for="start_date">Дата начала:</label>
                <input type="date" id="start_date" name="start_date" required>
            </div>
            <div class="form-group">
                <label for="duration_months">Продолжительность (мес.):</label>
                <input type="number" id="duration_months" name="duration_months" min="1" required>
            </div>
            <button type="submit" name="add_lease" class="btn">Добавить аренду</button>
        </form>
    </div>
</div>
';

require_once '../src/views/layout.php';
ob_end_flush();
?>