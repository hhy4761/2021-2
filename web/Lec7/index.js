var divContents = document.getElementById('parentDiv');
var divContentsC = document.getElementsByClassName('divClass');

console.log(divContentsC[0]);
divContents.children[0].innerHTML = "Hello World";
divContents.children[0].style.color = 'blue';
divContents.children[0].style.fontSize = '30px';
divContents.children[0].style.display = 'none';
divContents.children[0].style.display = 'block';
// document.getElementById('btnAction').addEventListener('click',myFunction);
document.getElementById('btnAction').onmousemove = myFunction;

function myFunction(){
    arr = ['hello','hi','where are you?']
    var randomValue = Math.floor(Math.random()*arr.length)
    alert(arr[randomValue]);
}