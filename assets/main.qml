import bb.cascades 1.0
import bb.device 1.0

Page 
{
    property bool ledStatus : false
    property bool firstRun : true
    
    titleBar: TitleBar 
    {
        title: "Ultra Camera Flasher"
    }
    
    ScrollView 
    {
	    Container
	    {
	        topPadding: 40
	        bottomPadding: 40
	        leftPadding: 40
	        rightPadding: 40
	
	        Label 
	        {
	            id: lblFlashSpeed
	            text: "Flash Speed"
	        }
	        
	        Slider 
	        {
	            id: flashSpeed
	            toValue: 1.0
	            fromValue: 0.0
	            value: 0.8
	
	            onValueChanged: 
	            {
                    lblFlashSpeed.text = "Flash Speed: " + (Math.ceil((1.0 - flashSpeed.value) * 100) / 100) + " (in seconds)"
                    
                    if(!firstRun)
                    {
                        _app.stopFlashing();
                        _app.startFlashing(1000 - (flashSpeed.value * 1000), maxTimes.text * 2);
                        btnStartFlashing.enabled = false;
                        btnStopFlashing.enabled = true;
                    }
                    else 
                    {
                        firstRun = false;
                    }
	            }
	        }
	        
	        Label 
	        {
	            text: "Flash Times"
	        }
	        
	        TextField 
	        {
	            id: maxTimes
	            text: "100"
	            horizontalAlignment: HorizontalAlignment.Fill
	            inputMode: TextFieldInputMode.NumbersAndPunctuation
	        }
	        
	        Header 
	        {
	            title: "Presets"
	            bottomMargin: 20
	        }
	        
	        Container 
	        {
	            layout: StackLayout 
	            {
	                orientation: LayoutOrientation.TopToBottom
	            }
	            
	            Container 
	            {
	                bottomMargin: 15
	                
	                layout: StackLayout 
	                {
	                    orientation: LayoutOrientation.LeftToRight
	                }
	                
	                Button 
	                {
	                    text: "Ultra Fast"  
	                    onClicked: 
	                    {
	                        _app.startFlashing(0.11 * 1000, maxTimes.text * 2);
                            btnStartFlashing.enabled = false;
                            btnStopFlashing.enabled = true;
	                    }
	                }
	                
	                Button 
	                {
	                    text: "Very Fast"    
	                    onClicked: 
	                    {
	                        _app.startFlashing(0.13 * 1000, maxTimes.text * 2);
                            btnStartFlashing.enabled = false;
                            btnStopFlashing.enabled = true;
	                    }
	                }
	            }
	            
	            Container 
	            {
	                bottomMargin: 15
	                
	                layout: StackLayout 
	                {
	                    orientation: LayoutOrientation.LeftToRight
	                }
	                
	                Button 
	                {
	                    text: "Fast"
	                    onClicked: 
	                    {
	                        _app.startFlashing(0.30 * 1000, maxTimes.text * 2);
                            btnStartFlashing.enabled = false;
                            btnStopFlashing.enabled = true;
	                    }
	                }
	                
	                Button 
	                {
	                    text: "Slow" 
	                    onClicked: 
	                    {
	                        _app.startFlashing(0.50 * 1000, maxTimes.text * 2);
                            btnStartFlashing.enabled = false;
                            btnStopFlashing.enabled = true;
	                    }   
	                }
	            }
	            
	            Container 
	            {
	                bottomMargin: 15
	                
	                layout: StackLayout 
	                {
	                    orientation: LayoutOrientation.LeftToRight
	                }
	                
	                Button 
	                {
	                    text: "Very Slow"
	                    onClicked: 
	                    {
	                        _app.startFlashing(0.90 * 1000, maxTimes.text * 2);
                            btnStartFlashing.enabled = false;
                            btnStopFlashing.enabled = true;
	                    }
	                }
	                
	                Button 
	                {
	                    text: "Ultra Slow" 
	                    onClicked: 
	                    {
	                        _app.startFlashing(1.50 * 1000, maxTimes.text * 2);
                            btnStartFlashing.enabled = false;
                            btnStopFlashing.enabled = true;
	                    }
	                }
	            }
	            
                Header 
                {
                    title: "LED"
                    bottomMargin: 20
                }
	            
                DropDown {
                    id: colorChooser
                    horizontalAlignment: HorizontalAlignment.Center
                    
                    title: "LED Color"
                    
                    Option {
                        text: "Red"
                        value: LedColor.Red
                        imageSource: "asset:///images/red.png"
                        selected: true
                    }
                    
                    Option {
                        text: "Green"
                        value: LedColor.Green
                        imageSource: "asset:///images/green.png"
                    }
                    
                    Option {
                        text: "Blue"
                        value: LedColor.Blue
                        imageSource: "asset:///images/blue.png"
                    }
                    
                    Option {
                        text: "Yellow"
                        value: LedColor.Yellow
                        imageSource: "asset:///images/yellow.png"
                    }
                    
                    Option {
                        text: "Cyan"
                        value: LedColor.Cyan
                        imageSource: "asset:///images/cyan.png"
                    }
                    
                    Option {
                        text: "Magenta"
                        value: LedColor.Magenta
                        imageSource: "asset:///images/magenta.png"
                    }
                    
                    Option {
                        text: "White"
                        value: LedColor.White
                        imageSource: "asset:///images/white.png"
                    }
                }
                
                Button 
                {
                    id: btnLedOnOff
                    text: "LED On"
                    imageSource: "asset:///images/on.png"
                    horizontalAlignment: HorizontalAlignment.Fill
                    onClicked: 
                    {
                        ledStatus = !ledStatus;
                        
                        if(ledStatus == true)
                        {
                            text = "LED Off";
                            imageSource = "asset:///images/off.png"
                            led.flash();
                        }
                        else if(ledStatus == false)
                        {
                            text = "LED On";
                            imageSource = "asset:///images/on.png"
                            led.cancel();
                        }
                    }
                }
	        }
	    }
	}
    
    actions: 
    [
        ActionItem 
        {
            id: btnStartFlashing
            title: "Start Flash"
            ActionBar.placement: ActionBarPlacement.OnBar
            imageSource: "asset:///images/play.png"
            onTriggered: 
            {
                _app.startFlashing(1000 - (flashSpeed.value * 1000), maxTimes.text * 2);
                btnStartFlashing.enabled = false;
                btnStopFlashing.enabled = true;
            }  
        },
        ActionItem 
        {
            id: btnStopFlashing
            title: "Stop Flash"
            ActionBar.placement: ActionBarPlacement.OnBar
            imageSource: "asset:///images/stop.png"
            enabled: false;
            onTriggered: 
            {
            	_app.stopFlashing();
                btnStartFlashing.enabled = true;
                btnStopFlashing.enabled = false;
            }
        },
        ActionItem 
        {
            id: onoff
            title: "Flash Off"
            ActionBar.placement: ActionBarPlacement.OnBar
            imageSource: "asset:///images/on.png"
            onTriggered: 
            {
                _app.toggleFlashlight();
                
                if(_app.flashlightStatus() == true)
                {
                    title = "Flash Off";
                    imageSource = "asset:///images/off.png"
                }
                else if(_app.flashlightStatus() == false)
                {
                    title = "Flash On";
                    imageSource = "asset:///images/on.png"
                }
            }
        },
        ActionItem 
        {
            title: "Share Our App"
            ActionBar.placement: ActionBarPlacement.InOverflow
            imageSource: "asset:///images/share.png"
            attachedObjects: 
            [
                Invocation 
                {
                    id: invokeShare
                    query 
                    {
                        mimeType: "text/plain"
                        invokeActionId: "bb.action.SHARE"
                        invokerIncluded: true
                        data: 'I am using "Ultra Camera Flasher" for BlackBerry 10! And I love it! Download it at http://appworld.blackberry.com/webstore/content/38571892'
                    }
                }
            ]
            onTriggered: 
            {
                invokeShare.trigger("bb.action.SHARE")
            }
        },
        ActionItem 
        {
            title: "Rate Our App"
            ActionBar.placement: ActionBarPlacement.InOverflow
            imageSource: "asset:///images/rate.png"
            onTriggered: 
            {
                _app.invokeBBWorld("appworld://content/38571892");
            }
        }
    ]
    
    Menu.definition: MenuDefinition 
    {
        actions: 
        [
            ActionItem 
            {
                title: "About"
                imageSource: "asset:///images/about.png"
                onTriggered: 
                {
                    aboutSheet.open();
                }
                attachedObjects: AboutSheet 
                {
                    id: aboutSheet
                }
            },
            ActionItem  
            {
                title: "Contact Us"
                imageSource: "asset:///images/contact.png"
                onTriggered: 
                {
                    _app.invokeEmail("nemoryoliver@gmail.com", "Support : Ultra Camera Flasher ", "How may we help you?\n\n")
                }
            }
            ,
//            ActionItem 
//            {
//                title: "Settings"
//                imageSource: "asset:///images/settings.png"
//                enabled: false
//                onTriggered:
//                {
//                    settingsSheet.open();
//                }
//                attachedObjects: SettingsSheet {
//                    id: settingsSheet
//                }
//            },
            ActionItem 
            {
                title: "Rate Our App"
                imageSource: "asset:///images/rate.png"
                enabled: true
                onTriggered:
                {
                    _app.invokeBBWorld("appworld://content/38571892");
                }
            }
        ]
    }
    
    attachedObjects: Led 
    {
    	id: led
        color: colorChooser.selectedValue
    }
}
