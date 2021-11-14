var home = document.getElementById('home')
var again = document.getElementById('another')
var ret = document.getElementById('return')

home.addEventListener('click',go_menu)
again.addEventListener('click',again_transfer)
ret.addEventListener('click',init)

function go_menu(){ // go menu
    window.location.href = 'menu.html'
}

function again_transfer(){ //transfer again
    window.location.href = 'transfer.html'
}

function init(){ //go to first page
    window.location.href = 'Intro.html'
}
