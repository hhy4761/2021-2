
var home = document.getElementById('home')
var again = document.getElementById('again')
var ret = document.getElementById('return')

home.addEventListener('click',go_menu)
again.addEventListener('click',again_deposit)
ret.addEventListener('click',init)

function go_menu(){ //go menu
    window.location.href = 'menu.html'
}

function again_deposit(){ //deposit again
    window.location.href = 'deposit.html'
}

function init(){ // you can go first page
    window.location.href = 'Intro.html'
}
