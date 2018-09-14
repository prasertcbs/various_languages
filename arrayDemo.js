/**
 * demo JavaScript array
 */
function demo1() {
    document.write("demo1()" + "<p/>");
    var ar = [10, 20, 30];
    for (var i = 0; i < ar.length; i++) {
        document.write(ar[i] + "<br/>")
    }
}

function demo2() {
    var ar = [];
    ar[0] = 10;
    ar[1] = 20;
    ar[2] = 30;
    document.write("demo2()" + "<p/>");
    document.write(ar + "<p/>");
    for (var i = 0; i < ar.length; i++) {
        document.write(ar[i] + "<br/>")
    }
}

function demo3() {
    var ar = new Array(10, 20, 30);
    //var ar = [10, 20, 30];
    document.write("demo3()" + "<p/>");
    document.write(ar + "<p/>");

    var ar2 = new Array(3); //
    ar[0] = 10;
    ar[1] = 20;
    ar[2] = 30;
}

function twoDim() {
    var items = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
        [10, 11, 12]
    ];
    alert(items[2][1]); // 8
    alert(items[2]); // [7, 8, 9]
}

function dayColor() {
    var items = [
        ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"],
        [0xFF0000, 0xFFFF00, 0xFF66FF, 0x66CC00, 0xFF9900, 0x66FFFF, 0x9900FF]
    ];
    alert(items[0][3]);
    alert(items[0]);
    alert(items[1]);
}


function arrayObj() {
    var products = [
        {id: "C001", model: "Canon 6D", price: 2},
        {id: "S007", model: "Sony A7", price: 3},
        {id: "N325", model: "Nikon D750", price:.48}
    ];
    alert(products[1].model);
    var total = 0.0;
    for (var i = 0; i < products.length; i++) {
        console.log("id = " + products[i].id + ", " + "model = " + products[i].model + ", " + "price = " + products[i].price);
        total = total + products[i].price;
    }
    alert(total);
}

//demo2();
//twoDim();
//dayColor();
arrayObj();