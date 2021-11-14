var info = document.getElementById('btn_info')
var withdraw = document.getElementById('btn_withdraw')
var deposit = document.getElementById('btn_deposit')
var transfer = document.getElementById('btn_transfer')
var back = document.getElementById('back')

info.addEventListener('click', show_info)
withdraw.addEventListener('click',show_withdraw)
deposit.addEventListener('click',show_deposit)
transfer.addEventListener('click',show_transfer)
back.addEventListener('click',init)

function show_info(){ // go to account info
    window.location.href = 'account_information.html'
}
function show_withdraw(){ // go to withdraw
    window.location.href = 'withdraw.html'
}
function show_deposit(){ //go to deposit
    window.location.href = 'deposit.html'
}
function show_transfer(){ //go to transfer
    window.location.href = 'transfer.html'
}
function init(){ // go to first page
    window.location.href = 'Intro.html'
}