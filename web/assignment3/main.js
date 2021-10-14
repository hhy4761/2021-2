
var q1 = ['Where is capital of South Korea?','Seoul'];
var q2 = ['When is the Christmas?','25 December'];
var q3 = ['Where is the SKKU?','Suwon'];
var q4 = ['When is the halloween?','31 October'];
var questions = [q1,q2,q3,q4];
var selections = [['Seoul','Incheon','Daegu','Busan'],['25 December','23 December','24 December','26 December'],['Suwon','Incheon','Jeju','Bundang'],['31 October','29 October','30 October','28 October']];
document.getElementById('play').onclick = play;
document.getElementById('container').style.visibility = 'hidden';

var count = 0;
var score = 0;

var curScore = document.createElement()
function play(){
    document.getElementById('wrapper').style.backgroundImage='none';
    document.getElementById('wrapper').style.backgroundColor='rgb(236,245,255)';
    document.getElementById('intro').style.display='none';
    document.getElementById('container').style.visibility = 'visible';
    question();
}

function question(){
    var randomValue = Math.floor(Math.random()*4);
    document.getElementById('Q').innerHTML = questions[randomValue % 4][0];
    if(randomValue == 0){
        ans = questions[0][1];
        var rand = Math.floor(Math.random()*4); //rand has value 1~4
        s1 = document.getElementById('btn1');
        text1 = selections[0][rand%4]
        s1.innerHTML = text1;
        rand++;
        s2 = document.getElementById('btn2');
        text2 = selections[0][rand%4];
        s2.innerHTML = text2;
        rand++;
        s3 =  document.getElementById('btn3');
        text3 = selections[0][rand%4];
        s3.innerHTML = text3;
        rand++;
        s4 = document.getElementById('btn4');
        text4 = selections[0][rand%4];
        s4.innerHTML = text4;
        count++;
        if(ans==text1){
            s1.addEventListener('click',correct1);
            score++;
        }
        else{
            s1.addEventListener('click',wrong1);
        }
        function correct1(){
            s1.style.backgroundColor = 'blue';
        }
        function wrong1(){
            s1.style.backgroundColor = 'red';
        }
        if(ans==text2){
            s2.addEventListener('click',correct2);
        }
        else{
            s2.addEventListener('click',wrong2);
        }
        function correct2(){
            s2.style.backgroundColor = 'blue';
        }
        function wrong2(){
            s2.style.backgroundColor = 'red';
        }
        if(ans==text3){
            s3.addEventListener('click',correct3);
        }
        else{
            s3.addEventListener('click',wrong3);
        }
        function correct3(){
            s3.style.backgroundColor = 'blue';
        }
        function wrong3(){
            s3.style.backgroundColor = 'red';
        }
        if(ans==text4){
            s4.addEventListener('click',correct4);
        }
        else{
            s4.addEventListener('click',wrong4);
        }
        function correct4(){
            s4.style.backgroundColor = 'blue';
        }
        function wrong4(){
            s4.style.backgroundColor = 'red';
        }
        
        
    }
    else if(randomValue == 1){
        ans = questions[1][1];
        var rand = Math.floor(Math.random()*4); //rand has value 1~4
        s1 = document.getElementById('btn1');
        text1 = selections[1][rand%4]
        s1.innerHTML = text1;
        rand++;
        s2 = document.getElementById('btn2');
        text2 = selections[1][rand%4];
        s2.innerHTML = text2;
        rand++;
        s3 =  document.getElementById('btn3');
        text3 = selections[1][rand%4];
        s3.innerHTML = text3;
        rand++;
        s4 = document.getElementById('btn4');
        text4 = selections[1][rand%4];
        s4.innerHTML = text4;
        count++;
        if(ans==text1){
            s1.addEventListener('click',correct1);
        }
        else{
            s1.addEventListener('click',wrong1);
        }
        function correct1(){
            s1.style.backgroundColor = 'blue';
        }
        function wrong1(){
            s1.style.backgroundColor = 'red';
        }
        if(ans==text2){
            s2.addEventListener('click',correct2);
        }
        else{
            s2.addEventListener('click',wrong2);
        }
        function correct2(){
            s2.style.backgroundColor = 'blue';
        }
        function wrong2(){
            s2.style.backgroundColor = 'red';
        }
        if(ans==text3){
            s3.addEventListener('click',correct3);
        }
        else{
            s3.addEventListener('click',wrong3);
        }
        function correct3(){
            s3.style.backgroundColor = 'blue';
        }
        function wrong3(){
            s3.style.backgroundColor = 'red';
        }
        if(ans==text4){
            s4.addEventListener('click',correct4);
        }
        else{
            s4.addEventListener('click',wrong4);
        }
        function correct4(){
            s4.style.backgroundColor = 'blue';
        }
        function wrong4(){
            s4.style.backgroundColor = 'red';
        }
    }
    else if(randomValue == 2){
        ans = questions[2][1];
        var rand = Math.floor(Math.random()*4); //rand has value 1~4
        s1 = document.getElementById('btn1');
        text1 = selections[2][rand%4]
        s1.innerHTML = text1;
        rand++;
        s2 = document.getElementById('btn2');
        text2 = selections[2][rand%4];
        s2.innerHTML = text2;
        rand++;
        s3 =  document.getElementById('btn3');
        text3 = selections[2][rand%4];
        s3.innerHTML = text3;
        rand++;
        s4 = document.getElementById('btn4');
        text4 = selections[2][rand%4];
        s4.innerHTML = text4;
        count++;
        if(ans==text1){
            s1.addEventListener('click',correct1);
        }
        else{
            s1.addEventListener('click',wrong1);
        }
        function correct1(){
            s1.style.backgroundColor = 'blue';
        }
        function wrong1(){
            s1.style.backgroundColor = 'red';
        }
        if(ans==text2){
            s2.addEventListener('click',correct2);
        }
        else{
            s2.addEventListener('click',wrong2);
        }
        function correct2(){
            s2.style.backgroundColor = 'blue';
        }
        function wrong2(){
            s2.style.backgroundColor = 'red';
        }
        if(ans==text3){
            s3.addEventListener('click',correct3);
        }
        else{
            s3.addEventListener('click',wrong3);
        }
        function correct3(){
            s3.style.backgroundColor = 'blue';
        }
        function wrong3(){
            s3.style.backgroundColor = 'red';
        }
        if(ans==text4){
            s4.addEventListener('click',correct4);
        }
        else{
            s4.addEventListener('click',wrong4);
        }
        function correct4(){
            s4.style.backgroundColor = 'blue';
        }
        function wrong4(){
            s4.style.backgroundColor = 'red';
        }
    }
    else{
        ans = questions[3][1];
        var rand = Math.floor(Math.random()*4); //rand has value 1~4
        s1 = document.getElementById('btn1');
        text1 = selections[3][rand%4]
        s1.innerHTML = text1;
        rand++;
        s2 = document.getElementById('btn2');
        text2 = selections[3][rand%4];
        s2.innerHTML = text2;
        rand++;
        s3 =  document.getElementById('btn3');
        text3 = selections[3][rand%4];
        s3.innerHTML = text3;
        rand++;
        s4 = document.getElementById('btn4');
        text4 = selections[3][rand%4];
        s4.innerHTML = text4;
        count++;
        if(ans==text1){
            s1.addEventListener('click',correct1);
        }
        else{
            s1.addEventListener('click',wrong1);
        }
        function correct1(){
            s1.style.backgroundColor = 'blue';
        }
        function wrong1(){
            s1.style.backgroundColor = 'red';
        }
        if(ans==text2){
            s2.addEventListener('click',correct2);
        }
        else{
            s2.addEventListener('click',wrong2);
        }
        function correct2(){
            s2.style.backgroundColor = 'blue';
        }
        function wrong2(){
            s2.style.backgroundColor = 'red';
        }
        if(ans==text3){
            s3.addEventListener('click',correct3);
        }
        else{
            s3.addEventListener('click',wrong3);
        }
        function correct3(){
            s3.style.backgroundColor = 'blue';
        }
        function wrong3(){
            s3.style.backgroundColor = 'red';
        }
        if(ans==text4){
            s4.addEventListener('click',correct4);
        }
        else{
            s4.addEventListener('click',wrong4);
        }
        function correct4(){
            s4.style.backgroundColor = 'blue';
        }
        function wrong4(){
            s4.style.backgroundColor = 'red';
        }
    }
}
