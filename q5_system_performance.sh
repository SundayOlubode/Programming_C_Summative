#!/bin/bash

# Filename to store the log
LOGFILE="system_performance.log"

# Function to get CPU and memory usage
get_system_performance() {
  # Get CPU usage
  CPU_USAGE=$(top -bn1 | grep "Cpu(s)" | \
             sed "s/.*, *\([0-9.]*\)%* id.*/\1/" | \
             awk '{print 100 - $1"%"}')
  
  # Get memory usage
  MEM_USAGE=$(free | grep Mem | awk '{print $3/$2 * 100.0"%"}')
  
  # Get current timestamp
  TIMESTAMP=$(date "+%Y-%m-%d %H:%M:%S")
  
  # Write to logfile
  echo "$TIMESTAMP CPU: $CPU_USAGE, Memory: $MEM_USAGE" >> "$LOGFILE"
}

# Infinite loop to monitor system performance every 2 seconds
while true; do
  get_system_performance
  sleep 2
done
