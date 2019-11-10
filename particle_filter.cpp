int main()
{
    //Practice Interfacing with Robot Class
    Robot myrobot;
    myrobot.set_noise(5.0, 0.1, 5.0);
    myrobot.set(30.0, 50.0, M_PI / 2.0);
    myrobot.move(-M_PI / 2.0, 15.0);
    //cout << myrobot.read_sensors() << endl;
    myrobot.move(-M_PI / 2.0, 10.0);
    //cout << myrobot.read_sensors() << endl;

    //####   DON'T MODIFY ANYTHING ABOVE HERE! ENTER CODE BELOW ####

    // Instantiating 1000 Particles each with a random position and orientation
    int n = 1000;
    Robot p[n];

    //TODO: Your job is to loop over the set of particles
    //TODO: For each particle add noise: Forward_Noise=0.05, Turn_Noise=0.05, and Sense_Noise=5.0
    //TODO: And print its pose on a single line
    for(int i=0; i<n; i++) {
      p[i].set_noise(0.05, 0.05, 5.0);
      cout << p[i].show_pose() << endl;
    }

    //Now, simulate motion for each particle
    //TODO: Create a new particle set 'p2'
    //TODO: Rotate each particle by 0.1 and move it forward by 5.0
    //TODO: Assign 'p2' to 'p' and print the particle poses, each on a single line
    Robot p2[n];
    for(int j=0; j<n; j++) {
      p2[j].move(0.1, 5.0);
      p[j] = p2[j];
      cout << p[i].show_pose() << endl;
    }

    return 0;
}
