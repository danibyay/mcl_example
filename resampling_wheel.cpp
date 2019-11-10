int main()
{
    //Practice Interfacing with Robot Class
    Robot myrobot;
    myrobot.set_noise(5.0, 0.1, 5.0);
    myrobot.set(30.0, 50.0, M_PI / 2.0);
    myrobot.move(-M_PI / 2.0, 15.0);
    myrobot.move(-M_PI / 2.0, 10.0);

    // Create a set of particles
    int n = 1000;
    Robot p[n];

    for (int i = 0; i < n; i++) {
        p[i].set_noise(0.05, 0.05, 5.0);
    }

    //Re-initialize myrobot object and Initialize a measurment vector
    myrobot = Robot();
    vector<double> z;

    //Move the robot and sense the environment afterwards
    myrobot = myrobot.move(0.1, 5.0);
    z = myrobot.sense();

    // Simulate a robot motion for each of these particles
    Robot p2[n];
    for (int i = 0; i < n; i++) {
        p2[i] = p[i].move(0.1, 5.0);
        p[i] = p2[i];
    }

    //Generate particle weights depending on robot's measurement
    double w[n];
    for (int i = 0; i < n; i++) {
        w[i] = p[i].measurement_prob(z);
    }

    //####   DON'T MODIFY ANYTHING ABOVE HERE! ENTER CODE BELOW ####

    //TODO: Resample the particles with a sample probability proportional to the importance weight
    Robot p3[n];
    int index = gen_real_random() * n; // random number between [0 and 1000)
    double beta = 0.0;
    double max_w = max(w,n);
    for(int i=0; i<n; i++) {
      beta += gen_real_random() * 2 * max_w;
      while(w[index] < beta) {
        beta -= w[index];
        index += 1; // random index starts increasing
                    // if the weight of such index was smaller than random beta
      }
      // replace the particle on such index
      p[i] = p3[index];
    }
    // After replacing everything on p3, copy it to p,
    // the distribution of particles is no longer uniform.
    for (int k=0; k < n; k++) {
        p[k] = p3[k];
        cout << p[k].show_pose() << endl;
    }


    return 0;
}
