int main()
{
    // Instantiating a robot object from the Robot class
    Robot myrobot;

    // TODO: Set robot new position to x=10.0, y=10.0 and orientation=0
    // Fill in the position and orientation values in myrobot.set() function
    myrobot.set(10.0, 10.0, 0);

    // Printing out the new robot position and orientation
    cout << myrobot.show_pose() << endl;

    // TODO: Rotate the robot by PI/2.0 and then move him forward by 10.0
    // Use M_PI for the pi value
    myrobot.move(M_PI/2, 10.0);

    // TODO: Print out the new robot position and orientation
    cout << myrobot.show_pose() << endl;

    // Printing the distance from the robot toward the eight landmarks
    cout << myrobot.read_sensors() << endl;

    // if I want to turn clockwise its either negative angle
    // or complementary angle to 2*Pi
    // eg. turn clockwise x --> move(-x) or move(2pi-x)

    // TODO: Simulate Noise
    // Forward Noise=5.0, Turn Noise=0.1,Sense Noise=5.0
    myrobot.set_noise(5.0, 0.1, 5.0);

    return 0;
}
