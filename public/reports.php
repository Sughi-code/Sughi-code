<?php
require_once '../src/controllers.php';

ob_start();
$title = "Отчеты";

// Handle form submissions for reports and rent updates
if ($_POST) {
    if (isset($_POST['update_rent'])) {
        $type = $_POST['type'];
        $increase_percent = $_POST['increase_percent'];
        updatePropertyRentByTypeController($type, $increase_percent);
    }
}

$content = '
<div class="reports-section">
    <h2>Отчеты по системе аренды</h2>
    
    <div class="report-section">
        <h3>1. Объекты недвижимости заданного типа, в алфавитном порядке по убыванию или по возрастанию цены</h3>
        <form method="get">
            <div class="form-group">
                <label for="type1">Тип недвижимости:</label>
                <input type="text" id="type1" name="type1" value="' . (isset($_GET['type1']) ? htmlspecialchars($_GET['type1']) : '') . '">
            </div>
            <div class="form-group">
                <label for="order1">Сортировка:</label>
                <select id="order1" name="order1">
                    <option value="desc"' . (isset($_GET['order1']) && $_GET['order1'] === 'desc' ? ' selected' : '') . '>По алфавиту (убывание)</option>
                    <option value="asc"' . (isset($_GET['order1']) && $_GET['order1'] === 'asc' ? ' selected' : '') . '>По цене (возрастание)</option>
                </select>
            </div>
            <button type="submit" class="btn">Показать отчет</button>
        </form>
        
        ' . (isset($_GET['type1']) ? '
        <h4>Результаты:</h4>
        <table>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Тип</th>
                    <th>Ежемесячная аренда</th>
                </tr>
            </thead>
            <tbody>
        ' : '') . '
        
        ' . (isset($_GET['type1']) ? 
            (function() {
                $results = getPropertiesByTypeController($_GET['type1'], $_GET['order1'] ?? 'asc');
                $html = '';
                foreach ($results as $property) {
                    $html .= '
                    <tr>
                        <td>' . $property['property_id'] . '</td>
                        <td>' . htmlspecialchars($property['type']) . '</td>
                        <td>' . number_format($property['monthly_rent'], 2) . '</td>
                    </tr>';
                }
                if (!empty($results)) {
                    $html .= '</tbody></table>';
                } else {
                    $html .= '<p>Нет данных для отображения</p>';
                }
                return $html;
            })() : '') . '
    </div>
    
    <div class="report-section">
        <h3>2. Список арендаторов с объектами недвижимости и количеством аренд</h3>
        <table>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Фамилия</th>
                    <th>Количество аренд</th>
                </tr>
            </thead>
            <tbody>
        ';
        
        $tenants_rental_count = getTenantsWithRentalCountController();
        foreach ($tenants_rental_count as $tenant) {
            $content .= '
                <tr>
                    <td>' . $tenant['tenant_id'] . '</td>
                    <td>' . htmlspecialchars($tenant['last_name']) . '</td>
                    <td>' . $tenant['rental_count'] . '</td>
                </tr>
            ';
        }

        $content .= '
            </tbody>
        </table>
    </div>
    
    <div class="report-section">
        <h3>3. Список объектов недвижимости, которые никогда не сдавались в аренду</h3>
        <table>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Тип</th>
                    <th>Ежемесячная аренда</th>
                </tr>
            </thead>
            <tbody>
        ';
        
        $unrented_properties = getUnrentedPropertiesController();
        foreach ($unrented_properties as $property) {
            $content .= '
                <tr>
                    <td>' . $property['property_id'] . '</td>
                    <td>' . htmlspecialchars($property['type']) . '</td>
                    <td>' . number_format($property['monthly_rent'], 2) . '</td>
                </tr>
            ';
        }

        $content .= '
            </tbody>
        </table>
    </div>
    
    <div class="report-section">
        <h3>4. Объекты недвижимости, сданные в аренду более 3 раз</h3>
        <table>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Тип</th>
                    <th>Ежемесячная аренда</th>
                    <th>Количество аренд</th>
                </tr>
            </thead>
            <tbody>
        ';
        
        $properties_rented_more_than_3 = getPropertiesRentedMoreThan3TimesController();
        foreach ($properties_rented_more_than_3 as $property) {
            $content .= '
                <tr>
                    <td>' . $property['property_id'] . '</td>
                    <td>' . htmlspecialchars($property['type']) . '</td>
                    <td>' . number_format($property['monthly_rent'], 2) . '</td>
                    <td>' . $property['rental_count'] . '</td>
                </tr>
            ';
        }

        $content .= '
            </tbody>
        </table>
    </div>
    
    <div class="report-section">
        <h3>5. Объекты недвижимости, сданные в аренду более 2 раз и сроком более 1 года</h3>
        <table>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Тип</th>
                    <th>Ежемесячная аренда</th>
                    <th>Количество аренд</th>
                </tr>
            </thead>
            <tbody>
        ';
        
        $properties_rented_year = getPropertiesRentedMoreThan2TimesAndYearController();
        foreach ($properties_rented_year as $property) {
            $content .= '
                <tr>
                    <td>' . $property['property_id'] . '</td>
                    <td>' . htmlspecialchars($property['type']) . '</td>
                    <td>' . number_format($property['monthly_rent'], 2) . '</td>
                    <td>' . $property['rental_count'] . '</td>
                </tr>
            ';
        }

        $content .= '
            </tbody>
        </table>
    </div>
    
    <div class="report-section">
        <h3>6. Список объектов недвижимости с количеством аренд и общей суммой арендной платы</h3>
        <table>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Тип</th>
                    <th>Ежемесячная аренда</th>
                    <th>Количество аренд</th>
                    <th>Общая сумма аренды</th>
                </tr>
            </thead>
            <tbody>
        ';
        
        $properties_stats = getPropertiesWithRentalStatsController();
        foreach ($properties_stats as $property) {
            $content .= '
                <tr>
                    <td>' . $property['property_id'] . '</td>
                    <td>' . htmlspecialchars($property['type']) . '</td>
                    <td>' . number_format($property['monthly_rent'], 2) . '</td>
                    <td>' . ($property['rental_count'] ?? 0) . '</td>
                    <td>' . number_format($property['total_rent'] ?? 0, 2) . '</td>
                </tr>
            ';
        }

        $content .= '
            </tbody>
        </table>
    </div>
    
    <div class="report-section">
        <h3>7. Список арендаторов с количеством аренд и средней продолжительностью</h3>
        <table>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Фамилия</th>
                    <th>Количество аренд</th>
                    <th>Средняя продолжительность (мес.)</th>
                </tr>
            </thead>
            <tbody>
        ';
        
        $tenants_stats = getTenantsWithRentalStatsController();
        foreach ($tenants_stats as $tenant) {
            $content .= '
                <tr>
                    <td>' . $tenant['tenant_id'] . '</td>
                    <td>' . htmlspecialchars($tenant['last_name']) . '</td>
                    <td>' . $tenant['rental_count'] . '</td>
                    <td>' . number_format($tenant['avg_duration'] ?? 0, 2) . '</td>
                </tr>
            ';
        }

        $content .= '
            </tbody>
        </table>
    </div>
    
    <div class="report-section">
        <h3>8. Объекты недвижимости, сданные в аренду в заданном квартале</h3>
        <form method="get">
            <div class="form-group">
                <label for="year">Год:</label>
                <input type="number" id="year" name="year" min="2000" max="2030" value="' . (isset($_GET['year']) ? htmlspecialchars($_GET['year']) : date('Y')) . '">
            </div>
            <div class="form-group">
                <label for="quarter">Квартал:</label>
                <select id="quarter" name="quarter">
                    <option value="1"' . (isset($_GET['quarter']) && $_GET['quarter'] == '1' ? ' selected' : '') . '>1 квартал (Январь-Март)</option>
                    <option value="2"' . (isset($_GET['quarter']) && $_GET['quarter'] == '2' ? ' selected' : '') . '>2 квартал (Апрель-Июнь)</option>
                    <option value="3"' . (isset($_GET['quarter']) && $_GET['quarter'] == '3' ? ' selected' : '') . '>3 квартал (Июль-Сентябрь)</option>
                    <option value="4"' . (isset($_GET['quarter']) && $_GET['quarter'] == '4' ? ' selected' : '') . '>4 квартал (Октябрь-Декабрь)</option>
                </select>
            </div>
            <button type="submit" class="btn">Показать отчет</button>
        </form>
        
        ' . (isset($_GET['year']) && isset($_GET['quarter']) ? '
        <h4>Результаты:</h4>
        <table>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Тип</th>
                    <th>Дата начала аренды</th>
                </tr>
            </thead>
            <tbody>
        ' : '') . '
        
        ' . (isset($_GET['year']) && isset($_GET['quarter']) ? 
            (function() {
                $results = getPropertiesForQuarterController($_GET['year'], $_GET['quarter']);
                $html = '';
                foreach ($results as $property) {
                    $html .= '
                    <tr>
                        <td>' . $property['property_id'] . '</td>
                        <td>' . htmlspecialchars($property['type']) . '</td>
                        <td>' . $property['start_date'] . '</td>
                    </tr>';
                }
                if (!empty($results)) {
                    $html .= '</tbody></table>';
                } else {
                    $html .= '<p>Нет данных для отображения</p>';
                }
                return $html;
            })() : '') . '
    </div>
    
    <div class="report-section">
        <h3>9. Список арендаторов и количество различных объектов недвижимости, которые они арендовали</h3>
        <table>
            <thead>
                <tr>
                    <th>ID</th>
                    <th>Фамилия</th>
                    <th>Количество различных объектов</th>
                </tr>
            </thead>
            <tbody>
        ';
        
        $tenants_property_count = getTenantsWithPropertyCountController();
        foreach ($tenants_property_count as $tenant) {
            $content .= '
                <tr>
                    <td>' . $tenant['tenant_id'] . '</td>
                    <td>' . htmlspecialchars($tenant['last_name']) . '</td>
                    <td>' . $tenant['different_properties_count'] . '</td>
                </tr>
            ';
        }

        $content .= '
            </tbody>
        </table>
    </div>
    
    <div class="report-section">
        <h3>10. Изменение арендной платы для объектов заданного типа (на 12%)</h3>
        <form method="post">
            <div class="form-group">
                <label for="type">Тип недвижимости:</label>
                <select id="type" name="type" required>
                    <option value="">Выберите тип</option>
                    <option value="Квартира">Квартира</option>
                    <option value="Дом">Дом</option>
                    <option value="Офис">Офис</option>
                    <option value="Магазин">Магазин</option>
                </select>
            </div>
            <div class="form-group">
                <label for="increase_percent">Процент увеличения:</label>
                <input type="number" id="increase_percent" name="increase_percent" value="12" min="0" step="0.1">
            </div>
            <button type="submit" name="update_rent" class="btn">Изменить аренду</button>
        </form>
    </div>
</div>
';

require_once '../src/views/layout.php';
ob_end_flush();
?>