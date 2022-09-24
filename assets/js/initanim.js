$(document).ready(function() {
    var i = 0;
    var divs = $('.item');
    jQuery.each(divs, function() {
        var h = $(".header", this);
        var d = $(".details", this);
        var name = i.toString();

	 h.bind('click', function() { animatedcollapse.toggle(name); });
        d.attr("id", name);
        d.attr("style", "display: none");

        animatedcollapse.addDiv(name, 'fade=1,speed=200');

        i++;
    });

    animatedcollapse.init();

    //setTimeout("animatedcollapse.hideall();", 0);

    var t = 0;

    var actives = $('.active');
    jQuery.each(actives, function() {
        var d = $(".details", this);

        setTimeout("animatedcollapse.show(" + d.attr("id") + ")", t);
        t += 100;
    });
});

