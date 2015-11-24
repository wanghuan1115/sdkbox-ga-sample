
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {

        this._super();

        cc.log("GA Inited");
        sdkbox.PluginGoogleAnalytics.init();

        var size = cc.winSize;

        var logEventItem = new cc.MenuItemFont("LogEvent", function(){
          sdkbox.PluginGoogleAnalytics.logEvent("TestCategory", "Action", "Event", 1);
          sdkbox.PluginGoogleAnalytics.dispatchHits();
          cc.log("send event to ga");
        }, this);
        var m = new cc.Menu(logEventItem);
        this.addChild(m);

        // add a "close" icon to exit the progress. it's an autorelease object
        var closeItem = new cc.MenuItemImage(
            res.CloseNormal_png,
            res.CloseSelected_png,
            function () {
                cc.log("click");
            }, this);
        closeItem.attr({
            x: size.width - 20,
            y: 20,
            anchorX: 0.5,
            anchorY: 0.5
        });

        var menu = new cc.Menu(closeItem);
        menu.x = 0;
        menu.y = 0;
        this.addChild(menu, 1);

        return true;
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

