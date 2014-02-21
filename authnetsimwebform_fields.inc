<?php

/**
 * @file 
 * Authorize.Net SIM Webform Fields File
 *
 * Prepare and store the available linking fields for Authorize.Net, as well
 * as custom fields that are defined by the user.
 */
 
/**
 * Provide the required fields for Authorize.Net processing
 * 
 * @return array
 *  Provide an array containing the fields that are required by Authorize.Net
 */
function authnetsimwebform_available_fields() {
  
  return array(  
    //Special Field to block Processing
    0 => '--Do Not Map to an Authorize.Net field--',

    // Transaction Info
    'x_amount' => 'Amount',
    'anwf_quantity' => 'Quantity - Multiplies this number by Amount - 1 if not set',
    
    'x_description' => 'Transaction Description',
    
    'x_trans_id' => 'Transaction ID (Must be Mapped - Hidden Field)',
    
    //Cardholder Info
    'x_first_name' => 'First Name',
    'x_last_name' => 'Last Name',
    'x_address' => 'Address',
    'x_city' => 'City',
    'x_state' => 'State',
    'x_zip' => 'Zip',
    'x_email' => 'Email',
  );
}

/**
 * Provide any custom fields that users have defined in the admin section.
 *
 * @return $return_fields
 *  Provide an array containing any fields that were created by the user.
 */
function authnetsimwebform_load_custom_fields($loadtype) {
  $custom_fields = variable_get('authnetsimwebform_custom_fields', array());
  $return_fields = array();
  if (is_array($custom_fields)) {
    if ($loadtype == "webform") {
      foreach ($custom_fields as $cfkey => $cfvalue) {
        $cfkey = strtolower($cfkey);
        $return_fields[$cfkey] = $cfvalue;
      }
    }
    else {
      $return_fields = $custom_fields;
    }
    return $return_fields ;
  }
  else {
    return array();
  }
}