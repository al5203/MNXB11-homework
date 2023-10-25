#!/bin/sh
#SBATCH -J 'simple job'
#SBATCH --time=00:05:00
#SBATCH -A lu2023-7-4
ls -l /etc
ls -l /usr/bin/
hostname
who
df -h
sleep 5m
