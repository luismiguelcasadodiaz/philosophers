#!/bin/bash
start_time=$(date +%s%3N)  # start time in milliseconds

./philo_threads 4 800 200 200 20 > tirame

end_time=$(date +%s%3N)  # # end time in milliseconds
duration_ms=$((end_time - start_time))  # duration in milliseconds

echo "With Sanitize Thread Execution time in ms: $duration_ms"
start_time=$(date +%s%3N)  # start time in milliseconds

./philo_address 4 800 200 200 20 > tirame

end_time=$(date +%s%3N)  # # end time in milliseconds
duration_ms=$((end_time - start_time))  # duration in milliseconds

echo "With Sanitize Address Execution time in ms: $duration_ms"
start_time=$(date +%s%3N)  # start time in milliseconds

./philo_only 4 800 200 200 20 >tirame

end_time=$(date +%s%3N)  # # end time in milliseconds
duration_ms=$((end_time - start_time))  # duration in milliseconds

echo "Without Sanitize Execution time in ms: $duration_ms"
