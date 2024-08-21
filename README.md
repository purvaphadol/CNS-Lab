# Computer Networks and Security Lab

This repository contains the assignments I completed as part of the Computer Networks and Security Laboratory course. These assignments are designed to provide practical understanding and implementation of key concepts in computer networking and security. The assignments cover a range of topics, including error detection and correction, sliding window protocols, subnetting, routing, socket programming, and DNS lookup.

## Assignments Overview

1. **Error Detection and Correction using Hamming Codes or CRC**
   - **Description**: This program implements error detection and correction for 7/8-bit ASCII codes using Hamming Codes or Cyclic Redundancy Check (CRC). The objective is to ensure data integrity by detecting and correcting errors during data transmission.
   - **File Name**: `hamming.cpp` and `crc.cpp`

2. **Simulation of Go-Back-N and Selective Repeat Protocols**
   - **Description**: This program simulates Go-Back-N and Selective Repeat Modes of the Sliding Window Protocol in Peer-to-Peer mode. It demonstrates how these protocols manage data transmission and handle errors and retransmissions.
   - **File Name**: `go.cpp` and `sel.cpp`

3. **Subnetting and Subnet Mask Calculation**
   - **Description**: This program demonstrates subnetting by calculating subnet masks for given network addresses. It helps in understanding how subnetting can efficiently allocate IP addresses within a network.
   - **File Name**: `subnet.cpp`

4. **Distance Vector Routing Protocol**
   - **Description**: This program implements the Distance Vector Routing Protocol, which helps in finding the most suitable path for data transmission in a network. The program simulates how routers communicate and update their routing tables.
   - **File Name**: `dvr.cpp`

5. **TCP and UDP Socket Programming**
   - **Description**: This program uses TCP and UDP sockets in a wired network to perform the following tasks:
     - Say Hello to Each Other
     - File Transfer
   - **Folder Name**: `TCP` and `UDP`

6. **DNS Lookup Program**
   - **Description**: This program performs DNS lookup, where given an IP address as input, it returns the corresponding URL and vice-versa. It helps in understanding how DNS servers resolve domain names to IP addresses.
   - **File Name**: `dns.cpp`
