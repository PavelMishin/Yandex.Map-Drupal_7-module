(function($) {
ymaps.ready(init);

function init () {
    var myMap = new ymaps.Map('map', {
            center: [55.76, 37.64],
            zoom: 10
        } , {
            maxZoom: 12
        }
        ),
        objectManager = new ymaps.ObjectManager({
            clusterize: true,
            gridSize: 128
        });

    myMap.geoObjects.add(objectManager);

    $.ajax({
        url: "/sites/all/modules/yandex_map/coordinates.json"
    }).done(function(data) {
        objectManager.add(data);
    });

}
})(jQuery);