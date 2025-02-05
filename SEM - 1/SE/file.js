// Sample JavaScript code demonstrating various control structures

// Function to check if a number is even or odd
function isEvenOrOdd(number) {
    if (number % 2 === 0) {
        return "even";
    } else {
        return "odd";
    }
}

// Function to calculate the factorial of a number
function factorial(num) {
    let result = 1;
    for (let i = 1; i <= num; i++) {
        result *= i;
    }
    return result;
}

// Function to get a grade based on score
function getGrade(score) {
    switch (true) {
        case score >= 90:
            return "A";
        case score >= 80:
            return "B";
        case score >= 70:
            return "C";
        case score >= 60:
            return "D";
        default:
            return "F";
    }
}

// Array of numbers and finding primes in the array
const numbers = [23, 42, 17, 19, 56, 78, 89, 31];
let primes = [];

for (let i = 0; i < numbers.length; i++) {
    let isPrime = true;
    if (numbers[i] < 2) isPrime = false;
    for (let j = 2; j < numbers[i]; j++) {
        if (numbers[i] % j === 0) {
            isPrime = false;
            break;
        }
    }
    if (isPrime) primes.push(numbers[i]);
}

// Function with nested if and logical operators
function checkEligibility(age, hasID) {
    if (age >= 18 && hasID) {
        return "Eligible";
    } else if (age >= 18 && !hasID) {
        return "Eligible but needs ID";
    } else {
        return "Not eligible";
    }
}

// Simulate a countdown
function countdown(start) {
    while (start > 0) {
        console.log("Countdown: " + start);
        start--;
    }
    console.log("Blast off!");
}

// Example of combining multiple cases
function getSeason(month) {
    switch (month) {
        case "December":
        case "January":
        case "February":
            return "Winter";
        case "March":
        case "April":
        case "May":
            return "Spring";
        case "June":
        case "July":
        case "August":
            return "Summer";
        case "September":
        case "October":
        case "November":
            return "Fall";
        default:
            return "Unknown";
    }
}

// A loop with conditional and logical operators
for (let i = 1; i <= 10; i++) {
    if (i % 2 === 0 && i % 3 === 0) {
        console.log(i + " is divisible by both 2 and 3");
    } else if (i % 2 === 0 || i % 3 === 0) {
        console.log(i + " is divisible by either 2 or 3");
    }
}

// Find max in an array
function findMax(arr) {
    let max = arr[0];
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function using do-while loop
function sumOfDigits(number) {
    let sum = 0;
    do {
        sum += number % 10;
        number = Math.floor(number / 10);
    } while (number > 0);
    return sum;
}

// Using for loop with continue and break
for (let k = 1; k <= 20; k++) {
    if (k % 5 === 0) {
        console.log("Skipping " + k);
        continue;
    }
    if (k > 15) break;
    console.log("Current number: " + k);
}

// Array sorting using comparison function
function sortArray(arr) {
    return arr.sort((a, b) => a - b);
}

// Check if all numbers in array are positive
function areAllPositive(arr) {
    for (let num of arr) {
        if (num <= 0) return false;
    }
    return true;
}

// Simple Calculator
function calculator(a, b, operator) {
    switch (operator) {
        case "+":
            return a + b;
        case "-":
            return a - b;
        case "*":
            return a * b;
        case "/":
            return b !== 0 ? a / b : "Cannot divide by zero";
        default:
            return "Invalid operator";
    }
}

// Looping through an object
const studentGrades = {
    "Alice": 85,
    "Bob": 92,
    "Charlie": 78,
    "Diana": 89,
    "Eve": 95
};

for (const student in studentGrades) {
    console.log(`${student} has grade: ${studentGrades[student]}`);
}

// Checking prime number
function isPrime(num) {
    if (num < 2) return false;
    for (let i = 2; i <= Math.sqrt(num); i++) {
        if (num % i === 0) return false;
    }
    return true;
}

// Fibonacci series up to n terms
function fibonacci(n) {
    let fib = [0, 1];
    for (let i = 2; i < n; i++) {
        fib.push(fib[i - 1] + fib[i - 2]);
    }
    return fib;
}

// Calling various functions
console.log("Is 7 even or odd? ", isEvenOrOdd(7));
console.log("Factorial of 5: ", factorial(5));
console.log("Grade for score 88: ", getGrade(88));
console.log("Primes in the array: ", primes);
console.log("Eligibility check (age 20, ID true): ", checkEligibility(20, true));
countdown(5);
console.log("Season in March: ", getSeason("March"));
console.log("Max in array: ", findMax([12, 3, 78, 45, 67]));
console.log("Sum of digits (342): ", sumOfDigits(342));
console.log("All positive in [1, 2, 3]: ", areAllPositive([1, 2, 3]));
console.log("Calculator (5, 3, '+'): ", calculator(5, 3, '+'));
console.log("Is 13 prime? ", isPrime(13));
console.log("Fibonacci series (5 terms): ", fibonacci(5));
