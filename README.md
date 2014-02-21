authnetsimwebform
=================

Drupal module to allow direct flow from webform to authorize.net SIM payment form

The flow:
User fills out webform on Drupal site. 
Submission is recorded to the database.
User is directed to the Authorize.net payment form on Authorize.net's server.
After completing payment, user is returned to the Drupal site.
Submission is updated/marked as "paid".
Webform emails are sent.
Confirmation page displays.

2/21/14: I built this module for the Amherst Early Music Festival, and there are portions that are specific to their transactions. My goal is to anonymize this module further and make it more widely applicable.

To-do:
Get away from hard-coding NIDs and instead configure them through admin interface.
Create admin mapping from webform components to authnet x_ variables.
Permissions
