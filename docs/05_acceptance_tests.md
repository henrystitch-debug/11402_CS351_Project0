
# Acceptance Tests

## Overview
This document defines the acceptance criteria and test scenarios for the Two Sum solution.

## Business Requirements
- The solution must correctly identify two numbers that add up to a target sum
- The solution must return the indices of the two numbers
- The solution must handle edge cases and invalid inputs gracefully

## Acceptance Criteria

### AC1: Valid Two Sum Found
**Given** an array of integers and a target sum  
**When** two distinct numbers add up to the target  
**Then** return the indices of those two numbers

### AC2: No Solution Exists
**Given** an array where no two numbers sum to target  
**When** the function is called  
**Then** return an appropriate indicator (null, empty array, or exception)

### AC3: Edge Cases Handled
**Given** various edge cases  
**When** the function processes them  
**Then** behave correctly:
- Empty array
- Single element array
- Negative numbers
- Duplicate values

### AC4: Performance Requirements
**Given** large input arrays  
**When** the solution executes  
**Then** complete in O(n) time complexity

## Test Scenarios

| Scenario | Input | Expected Output | Status |
|----------|-------|-----------------|--------|
| Basic valid case | [2,7,11,15], target=9 | [0,1] | |
| No solution | [1,2,3], target=10 | null | |
| Negative numbers | [-1,3,5,-4], target=1 | [1,3] | |
| Empty array | [], target=5 | null | |