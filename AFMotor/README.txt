This is the August 12, 2009 Adafruit Motor shield firmware with basic Microstepping support. Works with all Arduinos and the Mega
Updated in September 2012 for use on PIC32 architecture (chipKIT/MPIDE)

For more information on the shield, please visit http://www.ladyada.net/make/mshield/

To install, click DOWNLOAD SOURCE in the top right corner, and see our tutorial at http://www.ladyada.net/library/arduino/libraries.html on Arduino Library installation


<?php echo str_replace('"', "", $this->escape($user->firstname) . " " . $this->escape($user->lastname)); ?>
$this->escape(str_replace('"', "", $user->firstname . " " . $user->lastname))
up.profile_value as firstname, up2.profile_value as lastname 

"left join (select user_id, profile_value FROM #__user_profiles Where profile_key = 'profile.firstname') as up on  up.user_id = u.id " .
"left join (select user_id, profile_value FROM #__user_profiles Where profile_key = 'profile.lastname') as up2 on  up2.user_id = u.id " .