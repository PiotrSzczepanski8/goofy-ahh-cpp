const form = document.querySelector("form");
const a_input = document.getElementById("a");
const output_p = document.getElementById("output");
const b_input = document.getElementById("b");

form.addEventListener("submit", function (event){
    // console.log(event);
    event.preventDefault();
    const clicked_button = event.submitter;
    const a = Number(a_input.value);
    const b = Number(b_input.value);

    switch (clicked_button.id){
        case "dodawanie":
            output_p.textContent = a + b;
            break;
        case "odejmowanie":
            output_p.textContent = a - b;
            break;
        case "mnozenie":
            output_p.textContent = a * b;
            break;
        case "dzielenie":
            output_p.textContent = a / b;
            break;
        case "reszta":
            output_p.textContent = a % b;
            break;
        case "calkowite":
            output_p.textContent = Math.trunc(a / b);
            break;
    }
});