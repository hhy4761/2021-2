let firstName = "ABCDE";
let lastName = "KK";
let age = 20;
age = 'old';
age = parseInt("52this is fun");
let weight = 40.5;
let graduated = true;

console.log(typeof undefined); // undefined type
console.log(typeof null); // object type
console.log(typeof age); // number(int,float) -> string
console.log(typeof graduated); //boolean
console.log("hello world!");
console.log(age);
console.log(firstName.indexOf('B'));
console.log(firstName[3]);
console.log(15+2);

let array = [1,2,3,'C',2.5,400,true];
console.log(typeof array); // object type
array[1] = "hello";
console.log(array);
array[7] = "he";
console.log(array);

for(let i=0; i<array.length; i++){
    console.log(array[i]);
}

let value = Math.floor(Math.random()*10+1);
console.log(value);

// alert("Welcome to the first lecture in JS");
let array2 = ["ff","aa","ab","gg","cc"];
aa = array2.sort();
console.log(aa);

function sayHello(lastName){
    console.log("Hello"+lastName);
}
sayHello(lastName);

