![Python](https://img.shields.io/badge/python-3.10-blue)
![Status](https://img.shields.io/badge/status-completed-success)

# Automata Theory Project

A foundational implementation of core concepts in **Automata Theory**, including finite automata, regular expressions, and state transition simulation.

This repository demonstrates how computational models such as DFA, NFA, and other automata types can be represented and executed using programmatic logic.

---

## Overview

Automata Theory is a fundamental subject in computer science that explores abstract machines and the problems they can solve. This project aims to provide working code that implements these theoretical models, allowing users to:

- Build and simulate finite automata  
- Evaluate regular expressions  
- Understand state transitions  
- Visualize automaton behavior

This repository serves both as an educational tool and as a code reference for automata simulations.

---

## Motivation

Automata Theory lies at the core of compiler design, formal verification, language processing, and algorithmic reasoning.  
This implementation bridges the gap between theory and practice, facilitating hands-on experimentation with common automata constructs.

---

## Key Features

- Deterministic Finite Automata (DFA) simulation  
- Non-deterministic Finite Automata (NFA) support  
- Regular expression parsing and evaluation  
- State transition visualization support  
- Modular code structure for extension

---

## Technologies Used

- **Python** – Primary implementation language  
- **NumPy** (optional) – For internal structure handling  
- **Graphviz / Outputs** – Visualization support  
- **Git & GitHub** – Version control

*(Adjust if another programming language is primarily used)*

---

## Repository Structure

```
otomata_teorisi/
│
├── automata/              # Core automata implementation
├── examples/              # Example automata definitions
├── tests/                 # Unit tests
├── visualizations/        # Output graphs or diagrams
│
├── main.py                # Entry point for simulations
├── requirements.txt       # Project dependencies
└── README.md              # Project documentation
```

---

## Installation and Setup

To run this project locally:

1. Clone the repository:

```bash
git clone https://github.com/beyzaekrem/otomata_teorisi.git
Navigate into the project folder:

cd otomata_teorisi
Create and activate a virtual environment (optional but recommended):

python3 -m venv .venv
source .venv/bin/activate   # Windows: .venv\Scripts\activate
Install required packages:

pip install -r requirements.txt
Running the Automata Simulator
To start the automata simulation interface:

python main.py
This script loads predefined automata examples and processes input strings to demonstrate state transitions and acceptance results.

Example Usage
Example workflows include:

Simulating a DFA with a given input

Testing NFA behavior with multiple paths

Parsing a regular expression into an automaton

Visualizing transitions using diagrams

What This Project Demonstrates
This repository highlights:

Implementation of formal automata constructs

Bridging theoretical CS concepts with working code

Modular project organization

Practical simulation of abstract machines

Future Improvements
Potential extensions include:

Turing machine simulation

GUI interface for building automata

Web-based visualization platform

Integration with language processing tools

Exporting automata diagrams into interactive views

Author
Developed by Beyza Ekrem
Computer Engineering Student
