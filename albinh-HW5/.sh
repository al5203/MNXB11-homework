#!/bin/sh
#SBATCH -J “simple job”
#SBATCH --time=00:01:00
#SBATCH -A lu2023-7-4
ls -l /etc
ls -l /usr/bin/
hostname
who
sleep 2m