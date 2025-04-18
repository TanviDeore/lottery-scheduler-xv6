# Lottery Scheduler for XV6

This project implements a lottery scheduler in the XV6 operating system, replacing its default round-robin scheduling with a ticket-based CPU allocation mechanism.

## Objectives

  1) Gain deeper knowledge of a real kernel, XV6
  2) Understand how a scheduler works in an operating system
  3) Replace the default scheduler with a lottery scheduling algorithm
  4) Create a graph to demonstrate that the scheduler behaves as expected

## Overview

## In lottery scheduling:

  1) Each process is assigned a number of "tickets"
  2) A random ticket is drawn during scheduling
  3) The process holding the winning ticket gets CPU time
  4) CPU time is allocated proportionally to ticket count

## Features

  1) Ticket Inheritance: Child processes inherit parent tickets
  2) System Call: settickets() allows dynamic ticket adjustment
  3) Fairness Graph: Project2_Graph.pdf shows ticket count vs. CPU share

## Modified Files

  1) proc.c, proc.h – Scheduling logic and process data
  2) sysproc.c, usys.S, syscall.c, user.h – System call additions

## How to Run

    git clone https://github.com/TanviDeore/lottery-scheduler-xv6.git
    cd lottery-scheduler-xv6
    make qemu

Use settickets() in user programs to test ticket behavior.
## Result
  The graph in Project2_Graph.pdf confirms that CPU time is distributed in proportion to ticket count.
The graph in Project2_Graph.pdf confirms that CPU time is distributed in proportion to ticket count.
