# TravelingSalemanGeneticAlgorithm

### This program finds near-optimal solutions to the travelling salesman problem by using a genetic algorithm.

#### I would reccomend lowering the number of generations if running in debug mode.

By default a random grid of cities will be created- to use cities with specific cordinates use the city constructor found at line 29 to add to the citylist (line 56)


## Sample run:

```

Of the 30 initial tours of the 50 cities the shortest distance was:     21576.8


The intial route was:
(80,235) -> (472,400) -> (578,369) -> (160,400) -> (844,800) -> (22,107) -> (605,374) -> (623,348) -> (180,289) -> (507,699) -> (72,60) -> (869,354) -> (703,142) -> (665,91) -> (624,380) -> (555,438) -> (911,479) -> (577,337) -> (870,480) -> (208,549) -> (28,417) -> (435,111) -> (722,512) -> (743,163) -> (991,440) -> (45,715) -> (452,295) -> (388,152) -> (475,134) -> (460,108) -> (560,888) -> (997,732) -> (848,761) -> (846,440) -> (665,245) -> (207,159) -> (745,38) -> (664,390) -> (666,414) -> (978,143) -> (878,102) -> (880,364) -> (820,814) -> (39,669) -> (510,605) -> (861,748) -> (690,787) -> (4,629) -> (38,242) -> (890,14) -> (80,235)


After 5000 generations, the shortest route is:  6055.78.
This is an improvement of 71.9339%


The evolved route is:
(39,669) -> (4,629) -> (28,417) -> (38,242) -> (72,60) -> (22,107) -> (180,289) -> (80,235) -> (207,159) -> (388,152) -> (475,134) -> (435,111) -> (460,108) -> (665,91) -> (745,38) -> (890,14) -> (978,143) -> (878,102) -> (743,163) -> (703,142) -> (665,245) -> (664,390) -> (624,380) -> (605,374) -> (555,438) -> (577,337) -> (578,369) -> (623,348) -> (666,414) -> (722,512) -> (911,479) -> (991,440) -> (880,364) -> (869,354) -> (846,440) -> (870,480) -> (997,732) -> (848,761) -> (844,800) -> (820,814) -> (861,748) -> (690,787) -> (560,888) -> (507,699) -> (510,605) -> (472,400) -> (452,295) -> (160,400) -> (208,549) -> (45,715) -> (39,669)


Evolving for 5000 generations took 3889 ticks.
Press any key to continue . . .

```
