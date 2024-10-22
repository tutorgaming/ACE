rosrun gazebo spawn_model -file `rospack find angen_gazebo`/urdf/sensors/contact_sensors/FCS_bedroom.urdf -urdf -z 0.0505 -model FCS_br
rosrun gazebo spawn_model -file `rospack find angen_gazebo`/urdf/sensors/contact_sensors/FCS_kitchen.urdf -urdf -z 0.0505 -model FCS_k
rosrun gazebo spawn_model -file `rospack find angen_gazebo`/urdf/sensors/contact_sensors/FCS_workroom.urdf -urdf -z 0.0505 -model FCS_wr
rosrun gazebo spawn_model -file `rospack find angen_gazebo`/urdf/sensors/contact_sensors/FCS_livingroom.urdf -urdf -z 0.0505 -model FCS_lr
rosrun gazebo spawn_model -file `rospack find angen_gazebo`/urdf/sensors/contact_sensors/FCS_entranceway.urdf -urdf -z 0.0505 -model FCS_e
rosrun gazebo spawn_model -file `rospack find angen_gazebo`/urdf/sensors/contact_sensors/WCS_bedroom.urdf -urdf -z 0.7492 -model WCS_br
rosrun gazebo spawn_model -file `rospack find angen_gazebo`/urdf/sensors/contact_sensors/WCS_kitchen.urdf -urdf -z 0.7492 -model WCS_k
rosrun gazebo spawn_model -file `rospack find angen_gazebo`/urdf/sensors/contact_sensors/WCS_workroom.urdf -urdf -z 0.7492 -model WCS_wr
rosrun gazebo spawn_model -file `rospack find angen_gazebo`/urdf/sensors/contact_sensors/WCS_livingroom.urdf -urdf -z 0.7492 -model WCS_lr
rosrun gazebo spawn_model -file `rospack find angen_gazebo`/urdf/sensors/contact_sensors/DCS_entrance.urdf -urdf -z -0.0005 -model DCS_e

