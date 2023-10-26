document.addEventListener("DOMContentLoaded", function () {
  const modals = document.getElementById('myModal');
  const imgs = document.querySelectorAll('.thumbnail');
  const modalImg = document.getElementById("img01");
  const captionText = document.getElementById("caption");
  
  imgs.forEach((img) => {
      img.addEventListener('click', function(){
          modals.style.display = "block";
          modalImg.src = this.src;
          captionText.innerHTML = this.alt;
      });
  });
  
  const span = document.getElementsByClassName("close")[0];
  
  span.onclick = function() { 
      modals.style.display = "none";
  }
  
  // Add this code to close the modal when the background is clicked
  modals.addEventListener('click', function(event) {
      if (event.target === modals) {
          modals.style.display = "none";
      }
  });
});
