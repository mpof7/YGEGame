# YGEGame
Flock simulation project as part from my MSc studies



========================================================= Info  ======================================================

The project developed as part of the “Realistic Simulation” module's ICA, is a flock simulation
and it simulates the behaviour of a flock of bees following their leader by procedurally
producing their physical based animation. The design and development of the project was mostly
based on the “Craig W. Reynolds (1987) Flocks, Herds, and Schools: A Distributed Behavioral Model,
Computer Graphics, Volume 21, Number 4, July 1987” paper, the “Craig W. Reynolds Steering
Behaviors For Autonomous Characters” paper and the “AI for Game Developers by David M. Bourg
and Glenn Seemann, O'Reilly” as well as the “AI Game Programming Wisdom 2 by Steve Rabin”
books.

Apart from the above resources which were used as part of the research carried out for the
design and development of the specific simulation project, additional research included several
mathematical foundations, advanced numerical integration techniques, theoretical and applied
physics as well as software engineering and development approaches.

The flock simulation project was basically built upon the foundation of the three
flock behaviour rules; the separation, alignment and cohesion rules[Craig W. Reynolds]. 

The first and most important rule for simulating flock behaviour is, the separation rule, which basically refers
to the emergence of obtaining the appropriate collision avoidance among the members of the flock. Then, the
alignment rule comes with lower priority and basically refers to the flock members' tense to try and
match their velocities with their neighbourhood mates' average velocity. Finally, the cohesion rule
comes with the lowest priority and refers to the flock members' tense to try and move towards their
neighbourhood's centre (or in other words they try to match their position to their neighbourhood
mates' average position).

In the specific flock simulation there is also a “follow the leader”
behaviour added to the three main flocking behaviours due to the necessity of the flock members to
follow their leader. The final piece of the puzzle comprises the generated Catmull-Rom spline path
for the flock members (including the flock leader) to fly to.






================== USER GUIDE ==================================================================================================

1) Increment the flock's neighborhood range by pressing the 'A' key.
2) Decrement the flock's neighborhood range by pressing the 'Z' key.
3) Increment the minimum desired distance between the boids by pressing the 'S'key.
4) Decrement the minimum desired distance between the boids by pressing the 'X' key.
5) Increment the flock's collision avoidance weight value by pressing the 'W' key.
6) Decrement the flock's collision avoidance weight value by pressing the 'D' key.
7) Increment the flock's velocity matching weight value by pressing the 'E' key.
8) Decrement the flock's velocity matching weight value by pressing the 'F' key.
9) Increment the flock's centering weight value by pressing the 'R' key.
10) Decrement the flock's centering weight value by pressing the 'G' key.
