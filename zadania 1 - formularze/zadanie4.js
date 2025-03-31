const form = document.querySelector("form");

form.addEventListener('submit', function(event) {
    event.preventDefault();

    let sum = 0;
    let allValid = true;

    const inputs = document.querySelectorAll('.number-input');
    const checkboxes = document.querySelectorAll('input[type="checkbox"]');

    inputs.forEach((input, index) => {
        const value = input.value.trim();

        if (value !== "") {
            const number = Number(value); 

            if (isNaN(number) || !Number.isInteger(number)) {
                allValid = false;
            } else if (checkboxes[index].checked) {
                sum += number; 
            }
        }
    });

    if (!allValid) {
        alert("wprowadz tylko liczby calkowite");
        return;
    }

    document.getElementById('result').textContent = sum;
});