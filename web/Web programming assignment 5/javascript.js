var modal = document.querySelector(".pop"); 
var trigger = document.querySelector("#nav_btn"); 
var closeButton = document.querySelector(".close-button"); 
var cancelButton = document.querySelector("#cancel");
var delete_btn = document.querySelector('.btn')
const form = document.querySelector('.task-form')
const imgInput = document.querySelector('.image-url-input')
const titleInput = document.querySelector('.task-title-input')
const typeInput = document.querySelector('.task-type-input')
const descriptionInput = document.querySelector('.task-description-input')
const taskItems = document.querySelector('.lists')

let items =[]

//This is eventlistner for submit
form.addEventListener('submit',function(event){
    event.preventDefault();
    //If there are inputs in form, then program will add these items to LocalStorage
    addItem(imgInput.value,titleInput.value,typeInput.value,descriptionInput.value)
    imgInput.value = '';
    titleInput.value = '';
    typeInput.value = '';
    descriptionInput.value = '';
    //after click submit, close pop window
    pop()
})

function addItem(imgInput,titleInput,typeInput,descriptionInput){
    if(imgInput!=''&&titleInput!=''&&typeInput!=''&&descriptionInput!=''){
        //This is preparation for making JSON
        const item = {
            id: Date.now(),
            img: imgInput,
            title: titleInput,
            type: typeInput,
            description: descriptionInput
        };
        // add to items array
        items.push(item);
        addToLocalStorage(items);
    }

}

//This is to store to Local Storage
function addToLocalStorage(itemsArray){
    // After Making JSON, program will store JSON to Local Storage
    localStorage.setItem('items',JSON.stringify(itemsArray))
    // and program will show that it processed on front 
    renderTasksToHTML(itemsArray);
}

function renderTasksToHTML(array){
    taskItems.innerHTML=''
    // every element of items will be in html
    array.forEach(function(item){
        // making <div> </div>
        const div = document.createElement('div')
        // <div class='task-items> </div>
        div.setAttribute('class','task-items')
        // <div class='task-items data-key='item.id> </div>
        div.setAttribute('data-key',item.id)
        div.innerHTML=`
        <button class="delete-button">X</button> <br>
        <img src="${item.img}" class="img">
        <h3 class="title">${item.title}</h3>
        <div class="descript">${item.description}</div>
        <button class="type">${item.type}</button>
        `;
        // add div in <ul>
        taskItems.append(div)
    })
    
}

// show or not using toggle
function pop() { 
    modal.classList.toggle("show-modal"); 
}

// if click add task then pop form
function windowOnClick(event) { 
    if (event.target === modal) { 
        pop(); 
    } 
}

function getFromLocalStorage() {
    const reference = localStorage.getItem('items');
    // if reference exists
    if (reference) {
      items = JSON.parse(reference);
      renderTasksToHTML(items);
    }
  }

  function deleteTasks(id) {
    // Find out task that you want to delete using id

    items = items.filter(function(item) {
      return item.id != id;
    });
  
    // update the localStorage
    addToLocalStorage(items);
  }
  
taskItems.addEventListener('click', function(event) {
  
    // check if that is a delete-button
    if (event.target.classList.contains('delete-button')) {
      // delete from local storage using data-key
      deleteTasks(event.target.parentElement.getAttribute('data-key'));
    }
  });
  

trigger.addEventListener("click", pop); 
closeButton.addEventListener("click", pop); 
cancel.addEventListener("click", pop); 
window.addEventListener("click", windowOnClick); 
