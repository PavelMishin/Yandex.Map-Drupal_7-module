<?php

/**
 * Create the map according to Yandex.Map API https://tech.yandex.ru/maps/doc/jsapi/2.1/dg/concepts/object-manager/about-docpage/
 */
function yandex_map_page() {
    drupal_add_js('//api-maps.yandex.ru/2.1/?lang=ru-RU');
    drupal_add_js('//yandex.st/jquery/2.2.3/jquery.min.js');
    drupal_add_js(drupal_get_path('module', 'yandex_map') . '/yandex_map.js');
    return '<div id="map" style="width: 600px; height: 400px;"></div>';
}
