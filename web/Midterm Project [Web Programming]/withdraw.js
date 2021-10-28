var quick20 = document.getElementById('left1')
var quick40 = document.getElementById('left2')
var quick60 = document.getElementById('left3')
var quick80 = document.getElementById('left4')
var quick100 = document.getElementById('right1')
var quick200 = document.getElementById('right2')
var quick300 = document.getElementById('right3')
var back = document.getElementById('right4')
var input = document.getElementById('mid3')
var enter = document.getElementById('enter')
var plus100 = document.getElementById('mid1')
var plus20 = document.getElementById('mid2')
var minus20 = document.getElementById('mid4')
var minus100 = document.getElementById('mid5')

quick20.addEventListener('click',withdraw20)
quick40.addEventListener('click',withdraw40)
quick60.addEventListener('click',withdraw60)
quick80.addEventListener('click',withdraw80)
quick100.addEventListener('click',withdraw100)
quick200.addEventListener('click',withdraw200)
quick300.addEventListener('click',withdraw300)
back.addEventListener('click',menu)

plus100.addEventListener('click', add100)
plus20.addEventListener('click', add20)
minus20.addEventListener('click', sub20)
minus100.addEventListener('click', sub100)
enter.addEventListener('click',withdraw)

function withdraw20(){
    //Check if the amount can be withdrawn from the current available amount and send a message if not.
    localStorage.setItem('withdraw_money','20')
    var check = Number(localStorage.getItem('balance'))-Number(localStorage.getItem('withdraw_money'))
    if(check < 0){
        alert("You don't have enough money to withdraw. Check your account.")
    }
    else
    window.location.href = 'withdraw_yesorno.html'
}
function withdraw40(){
    //Check if the amount can be withdrawn from the current available amount and send a message if not.
    localStorage.setItem('withdraw_money','40')
    var check = Number(localStorage.getItem('balance'))-Number(localStorage.getItem('withdraw_money'))
    if(check < 0){
        alert("You don't have enough money to withdraw. Check your account.")
    }
    else
    window.location.href = 'withdraw_yesorno.html'
}
function withdraw60(){
    //Check if the amount can be withdrawn from the current available amount and send a message if not.
    localStorage.setItem('withdraw_money','60')
    var check = Number(localStorage.getItem('balance'))-Number(localStorage.getItem('withdraw_money'))
    if(check < 0){
        alert("You don't have enough money to withdraw. Check your account.")
    }
    else
    window.location.href = 'withdraw_yesorno.html'
}
function withdraw80(){
    //Check if the amount can be withdrawn from the current available amount and send a message if not.
    localStorage.setItem('withdraw_money','80')
    var check = Number(localStorage.getItem('balance'))-Number(localStorage.getItem('withdraw_money'))
    if(check < 0){
        alert("You don't have enough money to withdraw. Check your account.")
    }
    else
    window.location.href = 'withdraw_yesorno.html'
}
function withdraw100(){
    //Check if the amount can be withdrawn from the current available amount and send a message if not.
    localStorage.setItem('withdraw_money','100')
    var check = Number(localStorage.getItem('balance'))-Number(localStorage.getItem('withdraw_money'))
    if(check < 0){
        alert("You don't have enough money to withdraw. Check your account.")
    }
    else
    window.location.href = 'withdraw_yesorno.html'
}
function withdraw200(){
    //Check if the amount can be withdrawn from the current available amount and send a message if not.
    localStorage.setItem('withdraw_money','200')
    var check = Number(localStorage.getItem('balance'))-Number(localStorage.getItem('withdraw_money'))
    if(check < 0){
        alert("You don't have enough money to withdraw. Check your account.")
    }
    else
    window.location.href = 'withdraw_yesorno.html'
}
function withdraw300(){
    //Check if the amount can be withdrawn from the current available amount and send a message if not.
    localStorage.setItem('withdraw_money','300')
    var check = Number(localStorage.getItem('balance'))-Number(localStorage.getItem('withdraw_money'))
    if(check < 0){
        alert("You don't have enough money to withdraw. Check your account.")
    }
    else
    window.location.href = 'withdraw_yesorno.html'
}
function menu(){
    window.location.href = 'menu.html'
}
function add100(){
    //Check if the amount can be added. because we cannot withdraw over $300
    var num = Number(input.value) + 100
    if(num>300){
        alert('$300 is the limit to withdraw from the ATM')
        num -=100
    }
    input.value = num.toString()
}
function add20(){
    //Check if the amount can be added. because we cannot withdraw over $300
    var num = Number(input.value) + 20
    if(num>300){
        alert('$300 is the limit to withdraw from the ATM')
        num -=20
    }
    input.value = num.toString()
}
function sub100(){
    var num = Number(input.value) - 100
    if(num<0){
        num +=100
    }
    input.value = num.toString()
}
function sub20(){
    var num = Number(input.value) - 20
    if(num<0){
        num +=20
    }
    input.value = num.toString()
}
function withdraw(){
    //Check if the amount can be withdrawn from the current available amount and send a message if not.
    localStorage.setItem('withdraw_money',input.value)
    var check = Number(localStorage.getItem('balance'))-Number(localStorage.getItem('withdraw_money'))
    if(check < 0){
        alert("You don't have enough money to withdraw. Check your account.")
    }
    else
        window.location.href= 'withdraw_yesorno.html'
}