<?php

/**
 * Implements hook_form().
 */
function yandex_map_form()
{
    $form = array();

    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('GO'),
    );

    return $form;
}

/**
 * Implements hook_form_submit().
 */
function yandex_map_form_submit($form, &$form_state)
{
    //select the table whith geo fields
    $query = db_select('field_data_field_uaddress');

    //select geo fields
    $query
        ->fields('field_data_field_uaddress', array('bundle', 'entity_id', 'field_uaddress_data', 'field_uaddress_locality'))
        ->condition('entity_id', 0, '<>')
        ->condition('bundle', 'user')
        ->isNotNull('field_uaddress_data');

    $result = $query->execute()->fetchAll();

    //run batch to generate geojson
    yandex_map_unprogressive_batch($result);
}