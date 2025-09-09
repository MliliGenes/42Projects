# Philosophers

The Philosophers project is a classic synchronization problem from 42 school. The goal is to simulate a number of philosophers sitting around a table, alternately thinking and eating. The challenge is to prevent them from starving while avoiding deadlocks.

## The Problem

A number of philosophers are sitting at a round table. In the center of the table, there is a large bowl of spaghetti. Between each pair of philosophers, there is a single fork. To eat, a philosopher needs to pick up both the fork on their left and the fork on their right.

## The Simulation

The simulation takes the following arguments:

1. `number_of_philosophers`: The number of philosophers and also the number of forks.
2. `time_to_die`: The time in milliseconds that a philosopher will die if they don't eat.
3. `time_to_eat`: The time in milliseconds it takes for a philosopher to eat.
4. `time_to_sleep`: The time in milliseconds it takes for a philosopher to sleep.
5. `[number_of_times_each_philosopher_must_eat]`: (Optional) The number of times each philosopher must eat before the simulation ends.

## Implementation

The mandatory part of the project is implemented using **pthreads** and **mutexes**. Each philosopher is a thread, and each fork is a mutex.

The bonus part of the project is implemented using **processes** and **semaphores**. Each philosopher is a process, and the forks are represented by a semaphore.

## How to Run

1. **Compile the project:** Run `make` in the `philo` or `philo_bonus` directory.
2. **Run the simulation:** Execute the `philo` or `philo_bonus` binary with the required arguments.

### Example

```bash
# 5 philosophers, time to die is 800ms, time to eat is 200ms, time to sleep is 200ms
./philo 5 800 200 200
```
