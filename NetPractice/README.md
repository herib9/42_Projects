# NetPractice

*This project has been created as part of the 42 curriculum by hmolina*

## DESCRIPTION

## 📋 Table of Contents

- [Description](#-description)
- [Objectives](#-objectives)
- [Instructions](#-instructions)
- [Project Structure](#-project-structure)
- [Networking Concepts Covered](#-networking-concepts-covered)
- [Resolution Strategy](#-resolution-strategy)
- [Evaluation & Submission](#-evaluation--submission)
- [Resources](#-resources)


## 🎯 Description

**NetPractice** is a networking fundamentals project from the 42 curriculum designed to introduce students to the core concepts of computer networks through practical exercises.

The project consists of **10 progressive levels** that must be solved using a **web-based interactive simulator**. Each level requires configuring a small network so that devices can communicate successfully.

You will work with:

- IPv4 addressing
- Subnet masks
- Routing tables
- Default gateways
- Routers and switches

The primary goal is to develop a clear understanding of **how network communication works at a practical level**, rather than only at a theoretical level.


## 🎯 Objectives

The main learning objectives of NetPractice are:

- Understand **TCP/IP addressing**
- Learn how **subnetting** works
- Identify **network vs host portions** of an IP
- Configure **routing and gateways**
- Understand the role of **routers and switches**
- Diagnose network connectivity problems


## ⚙️ Instructions

### Running the Training Interfac

NetPractice is done through the official 42 web simulator.

To access it:

1. Open the NetPractice project page on the intra.
2. Launch the simulator in your browser.

How to Solve Levels

Each level requires:

Assign valid IP addresses

Configure subnet masks correctly

Set proper gateways

Configure routing tables when necessary

Ensure all devices can communicate

Use "Check again" to validate your configuration.

Exporting Configurations

Once a level is completed:

Click "Get my config"

Download the exported .json file

Save it locally

Repeat this process for all 10 levels.

Submission Requirements

Your repository must contain:

10 exported configuration files

One file per level

All placed at the root of the repository

Example:

netpractice/
├── level1.json
├── level2.json
├── level3.json
├── level4.json
├── level5.json
├── level6.json
├── level7.json
├── level8.json
├── level9.json
├── level10.json
└── README.md

🌐 Networking Concepts Covered

This project focuses on fundamental networking topics:

TCP/IP Addressing

Understanding IPv4 structure:

32-bit addresses

Network and host portions

Public vs private ranges

Subnet Masks

Learning how masks define:

Network boundaries

Available hosts

Broadcast addresses

CIDR Notation

Compact representation of subnet masks:

Examples:

/24 → 255.255.255.0
/26 → 255.255.255.192
/30 → 255.255.255.252

Default Gateways

Understanding how devices communicate outside their local network.

Routing

Configuring static routes to allow communication between networks.

Routers vs Switches

Switch: connects devices within the same network

Router: connects different networks

OSI Model Awareness

While not deeply explored, the project introduces concepts related to:

Layer 2 (Data Link)

Layer 3 (Network)

🧠 Resolution Strategy

A general approach to solving levels:

Identify the number of networks

Determine subnet ranges

Assign valid IP addresses

Configure gateways

Add routing rules when required

Validate connectivity

Common Mistakes

Using network address as host IP

Using broadcast address as host IP

Incorrect subnet masks

Missing routes between networks

📝 Evaluation & Submission
During Evaluation

You will have:

3 random levels

15 minutes total

No external tools are allowed except basic calculations.

Submission Checklist

Before submitting, verify:

All 10 levels exported

Files placed at repository root

README present and complete

📚 Resources
Documentation & References

RFC 1918 — Private IP Addressing

Cisco Networking Fundamentals

Subnetting tutorials and calculators

TCP/IP model documentation

Networking Concepts Studied

This project covers:

TCP/IP addressing

Subnet masks

CIDR notation

Default gateways

Static routing

Routers and switches

Basic OSI layer concepts

AI Usage Disclosure

AI tools were used for:

Structur the README file

Explain networking concepts

Formatting documentation

No AI was used to solve the NetPractice levels themselves.

All configurations were completed manually.