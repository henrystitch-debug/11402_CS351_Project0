

# Software Design Specification - Two Sum Problem

## 1. System Overview
This document describes the architecture and design for solving the Two Sum problem: finding two numbers in an array that sum to a target value.

## 2. System Architecture

### 2.1 High-Level Design
- **Input**: Array of integers and target sum
- **Output**: Indices of two numbers that sum to target
- **Constraint**: Each element used at most once

## 3. Design Patterns

### 3.2 Loop Approach
- **Pattern**: Loop-each-number
- **Time Complexity**: O(n²)

### 3.1 Hash Map Approach (Recommended)
- **Pattern**: Single-pass hash lookup
- **Time Complexity**: O(n)

## 4. Data Structures

| Structure | Purpose | Complexity |
|-----------|---------|-----------|
| HashMap/Dictionary | Store number-to-index mapping | O(1) lookup |
| Array | Input storage | Direct access |

## 5. Algorithm Selection

**Primary Algorithm**: Hash Map Approach
- Iterate through array once
- For each number, check if complement exists in map
- Store number and index in map

## 6. Technical Implementation Details

- Language: C
- Error Handling: Validate array size and null inputs
