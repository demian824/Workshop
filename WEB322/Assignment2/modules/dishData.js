/*
 * WEB322 – Assignment 2 (Winter 2021)
 * I declare that this assignment is my own work in accordance with Seneca Academic
 * Policy. No part of this assignment has been copied manually or electronically from
 * any other source (including web sites) or distributed to other students.
 *
 * Name:         Wonchul Choi
 * Student ID:   118362201
 * Course:       Web322 NDD
 *
 */

var dishes = [
    {
        name: "Spring Asparagus Plate",
        ingredient: "Aspagus, mushroom, potato, homemade prociutto, cream, butter, balsamic reduction",
        category: "seasonal",
        description: "Grilled Asparagus with prosciutto, saute mushroom, potato mousse and balsamic reduction",
        price: 25.99,
        serving: 2,
        time: 15,
        calorie: "300 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/asparagus_wrap.JPG',
        rate: 3.9
    },
    {
        name: "Beet leave wrap with Israeli couscous",
        ingredient: "Beet leave, Israeli couscous, plum jam, goat cheese, french dressing",
        category: "seasonal",
        description: "Israelli couscous salad wrapped with beet leaves with fresh plum jam",
        price: 19.99,
        serving: 2,
        time: 15,
        calorie: "300 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/beet_leave_wrap.JPG',
        rate: 4.0
    },
    {
        name: "Beef Brisket Poutine",
        ingredient: "Fresh beef brisket, D's signature beef gravy, fresh chees curd, Potato",
        category: "casual",
        description: "Traditional Canadian Beef Brisket Poutine",
        price: 25.99,
        serving: 2,
        time: 15,
        calorie: "500 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/brisket_poutine.JPG',
        rate: 4.0
    },
    {
        name: "D's Signiture Carbonara 2020 ver.",
        ingredient: "Homemade Fettuccine, Fresh Parmasan Cheese, Fresh egg yolk, Fresh garlic, Fresh parsley",
        category: "classic",
        description: "Traditional Carbonara was reborn by ours. Fit to Canadian taste",
        price: 32.99,
        serving: 2,
        time: 30,
        calorie: "500 per Person",
        isTopMeal: true,
        imageUrl: '/image/food/carbonara.JPG',
        rate: 4.5
    },
    {
        name: "Classic sunny-side up buger",
        ingredient: "Beef Petty, Letture, Bacon, Fresh egg, Sliced Mozzarella, Bun, French fries, Aioli",
        category: "classic",
        description: "Classic buger with sliced mozzarella, roasted bacon, sunny-side up, and aioli",
        price: 30.99,
        serving: 2,
        time: 30,
        calorie: "300 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/classic_buger.JPG',
        rate: 4.1
    },
    {
        name: "Korean Cold Noodle",
        ingredient: "White kimchi broth, Egg, Pear, Steamed beef, Cucumber, Buckwheat noodles",
        category: "ethnic",
        description: "Korean tradition cold noodle from the first recipe in Korea was reborn by our team.",
        price: 25.99,
        serving: 2,
        time: 30,
        calorie: "350 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/cold_noodle.JPG',
        rate: 4.0
    },
    {
        name: "Korean cucumber dumpling",
        ingredient: "Flour, Marinaded beef, Cucumber",
        category: "ethnic",
        description: "Korean tradition cucumber dumpling from the first recipe in Korea was reborn by our team.",
        price: 25.99,
        serving: 2,
        time: 60,
        calorie: "350 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/cucumber_dumpling.JPG',
        rate: 3.5
    },
    {
        name: "Dessert plate",
        ingredient: "Goat cheese cake, Black forest cake, Pecan pie, Fresh Berries, Fruit coulis and Jam ",
        category: "casual",
        description: "Sweet dessert plate for the special people! everything is in there",
        price: 30.99,
        serving: 4,
        time: 10,
        calorie: "300 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/dessert_plate.JPG',
        rate: 4.2
    },
    {
        name: "Duck congee with dry-aged beef",
        ingredient: "Duck confit, Rice, Grape fruit, Onion, carrot",
        category: "casual",
        description: "Homemade Duck confit with House dry-aged beef tender",
        price: 30.99,
        serving: 2,
        time: 45,
        calorie: "250 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/duck_congee.JPG',
        rate: 4.3
    },
    {
        name: "European seabass with seasonal vegetable",
        ingredient: "European seabass, seasonal vegetable, lobster sauce",
        category: "ethnic",
        description: "Fresh European seabass with carmelized seasonal vegetable and lobster sauce",
        price: 32.99,
        serving: 2,
        time: 45,
        calorie: "300 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/european_seabass.JPG',
        rate: 4.5
    },
    {
        name: "Heirloom Toamto Salad",
        ingredient: "Heirloom Tomato, Lonza, Baby spinich, Goat cheese, Avocado, Balsamic",
        category: "seasonal",
        description: "Fresh Heirloom Tomato, Baby sipnich salad with Homecured Lonza, Canadian goat cheese, guacamole and balsamic dressing",
        price: 25.99,
        serving: 2,
        time: 15,
        calorie: "200 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/heirloom_toamto_salad.JPG',
        rate: 4.0
    },
    {
        name: "Kimchi Seafood Pilaf with fried egg",
        ingredient: "Kimchi, Seasonal seafood, Rice, Fresh Egg",
        calorie: "casual",
        description: "Homemade kimchi with seasonal seafood and Special taste for Spicy lover!",
        price: 25.99,
        serving: 2,
        time: 15,
        calorie: "270 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/kimch_pilaf.JPG',
        rate: 4.1
    },
    {
        name: "Korean Braised Beef",
        ingredient: "Veal rip, Egg, pine nut, Special sauce",
        category: "ethnic",
        description: "Korean tradition Brasied Beef as known as Galbi from the first recipe in Korea is reborn by our team.",
        price: 32.99,
        serving: 2,
        time: 60,
        calory: "350 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/korean_braised_beef.JPG',
        rate: 4.0
    },
    {
        name: "Korean Style Wrap Plate",
        ingredient: "Marinade pork, Bean paste, Beef, Seasonal vegetable, Mixed Lettures",
        category: "ethnic",
        description: "Korean tradition style wrap with marinade pork and special meat and bean paste sauce from the first recipe in Korea.",
        price: 35.99,
        serving: 2,
        time: 15,
        calory: "300 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/korean_stlye_wrap.JPG',
        rate: 4.0
    },
    {
        name: "Lamb Burger ver 2020",
        ingredient: "Lamb petty, Aged whited chedder, Aged blue cheese, Hot aioli, Mixed Lettures",
        category: "casual",
        description: "Special flavor for meat lover! Our special lamb burger 2020 ver",
        price: 35.99,
        serving: 2,
        time: 30,
        calory: "250 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/lamb_burger.JPG',
        rate: 4.0
    },
    {
        name: "Pizzaroll",
        ingredient: "Mixed Homecured meat, Aged chedder, Homemade Tomato sauce, Olive oil, Mixed green, Balsamic Dressing ",
        category: "casual",
        description: "Pizza roll with mixed homecured meat, Aged chedder and mixed green salad.  ",
        price: 20.99,
        serving: 2,
        time: 45,
        calory: "300 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/pizzaroll.JPG',
        rate: 3.9
    },
    {
        name: "Potato Pizza",
        ingredient: "Homemade Tomato suace, Potato, Mixed cheese",
        category: "casual",
        description: "Special flavor roasted potato Pizza! ",
        price: 15.99,
        serving: 2,
        time: 45,
        calory: "200 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/potato_pizza.JPG',
        rate: 4.0
    },
    {
        name: "Farm Harvested Risotto",
        ingredient: "Arborio rice, Butternut Sqaush, Corn, Carrot, Onion, Parmigiano-Reggiano",
        category: "classic",
        description: "Farm Harvested Risotto make by traditional vegetable in North America.",
        price: 20.99,
        serving: 2,
        time: 60,
        calory: "200 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/risotto.JPG',
        rate: 4.0
    },
    {
        name: "Spring Salad with Smoked Salmon",
        ingredient: "club-smoked Salmon, Mixed spring green, French dressing ",
        category: "ethnic",
        description: "Korean tradition style wrap with marinade pork and special meat and bean paste sauce from the first recipe in Korea.",
        price: 20.99,
        serving: 2,
        time: 15,
        calory: "150 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/salad.JPG',
        rate: 4.0
    },
    {
        name: "Pan-fried Seabass with sous-vide vegetable",
        ingredient: "Seabass, Seasonal vegetable, Lemon-sauce",
        category: "seasonal",
        description: "Pan-fried tasty seabass! You will miss it all day! ",
        price: 50.99,
        serving: 2,
        time: 45,
        calory: "300 per Person",
        isTopMeal: true,
        imageUrl: '/image/food/seabass.JPG',
        rate: 4.8
    },
    {
        name: "Classic Italian Seafood Pasta",
        ingredient: "Homemade Tagliatelle, Mixed seafood, Oven-dried tomato, Olive oil-Extra Virgin",
        category: "classic",
        description: "Italian Classic Pasta on your table! Fresh seasonal seafood is going to you!",
        price: 52.99,
        serving: 2,
        time: 45,
        calory: "300 per Person",
        isTopMeal: true,
        imageUrl: '/image/food/seafood.JPG',
        rate: 4.9
    },
    {
        name: "Korean Steamed Tofu",
        ingredient: "Homemade Tofu, Chicken tenderloin, Egg, Pepper, Mushroom, Garlic",
        category: "ethnic",
        description: "Korean tradition Steamed Tofu with Chicken tenderloinfrom the first recipe in Korea is rebron by our team.",
        price: 35.99,
        serving: 2,
        time: 30,
        calory: "150 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/steamed_tofu.JPG',
        rate: 4.0
    },
    {
        name: "watermelon_salad",
        ingredient: "Marinade pork, Bean paste, Beef, Seasonal vegetable, Mixed Lettures",
        category: "seasonal",
        description: "Korean tradition style wrap with marinade pork and special meat and bean paste sauce from the first recipe in Korea.",
        price: 35.99,
        serving: 2,
        time: 15,
        calory: "300 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/watermelon_salad.JPG',
        rate: 4.0
    },
    {
        name: "Chicken Noodle Soup",
        ingredient: "Chicken breast, Chicken broth, Homemade pasta, Seasonal vegetable",
        category: "classic",
        description: "Chicken Noodle Soup for you. It makes you keep it warm.",
        price: 20.99,
        serving: 2,
        time: 30,
        calory: "150 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/chicken_noodle_soup.JPG',
        rate: 4.0
    },{
        name: "Smoked BBQ Rib",
        ingredient: "Veal Rib, Special BBQ sauce",
        category: "casual",
        description: "TGIF! Really BBQ Rib is coming!",
        price: 30.99,
        serving: 2,
        time: 30,
        calory: "300 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/Rib.JPG',
        rate: 4.0
    },
    {
        name: "French Lamb Rack",
        ingredient: "Lamb Rack ",
        category: "classic",
        description: "Chicken Noodle Soup for you. It makes you keep it warm.",
        price: 20.99,
        serving: 2,
        time: 30,
        calory: "150 per Person",
        isTopMeal: false,
        imageUrl: '/image/food/lamb_rack.JPG',
        rate: 4.0
    }

];

module.exports.getAllMenu = function() {
    return dishes;
};

module.exports.getTopMeal = function() {
    var topMeal = [];

    for (var i = 0; i < dishes.length; i++) {
        if (dishes[i].isTopMeal) {
            topMeal.push(dishes[i]);
        }
    }
    return topMeal;
};

module.exports.getClassic = function() {
    var classicMeal = [];

    for (var i = 0; i < dishes.length; i++) {
        if (dishes[i].category == "classic") {
            classicMeal.push(dishes[i]);
        }
    }
    return classicMeal;
};

module.exports.getCasual = function() {
    var casualMeal = [];

    for (var i = 0; i < dishes.length; i++) {
        if (dishes[i].category == "casual") {
            casualMeal.push(dishes[i]);
        }
    }
    return casualMeal;
};

module.exports.getEthnic = function() {
    var ethnicMeal = [];

    for (var i = 0; i < dishes.length; i++) {
        if (dishes[i].category == "ethnic") {
            ethnicMeal.push(dishes[i]);
        }
    }
    return ethnicMeal;
};


module.exports.getSeasonal = function() {
    var seasonalMeal = [];

    for (var i = 0; i < dishes.length; i++) {
        if (dishes[i].category == "seasonal") {
            seasonalMeal.push(dishes[i]);
        }
    }
    return seasonalMeal;
};


