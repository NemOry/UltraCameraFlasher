import bb.cascades 1.0
import bb.multimedia 1.0

Sheet 
{
    id: sheet
    peekEnabled: true

    Page 
    {
        titleBar: TitleBar 
        {
            title: "Settings"
            dismissAction: ActionItem 
            {
                title: "Close"
                onTriggered: 
                {
                    sheet.close();
                }
            }
        }
        
        Container 
        {
            topPadding: 100
            leftPadding: 50
            rightPadding: 50
            
            DropDown 
            {
                id: colorTheme
                title: "Color Theme (In the next version)"
                selectedIndex: 0
                enabled: false
                options: 
                [
                    Option
                    {
                        text: "Light"
                    },
                    Option
                    {
                        text: "Dark"
                    }
                ]
            }
            
            Header 
            {
                title: "Volume"
            }
            
            Slider 
            {
                id: volume
                horizontalAlignment: HorizontalAlignment.Fill
                onValueChanged: 
                {
                    
                }
            }
            
            Button 
            {
                text: "Done"
                horizontalAlignment: HorizontalAlignment.Fill
                onClicked: 
                {
                    _app.setSetting("colorTheme", colorTheme.selectedOption.text);
                    //_app.setSetting("volume", volume.value);	
                    _app.showToast("Successfully Set");
                    sheet.close();
                }
            }
        }    
    }
    
    attachedObjects: 
    [
        NowPlayingConnection 
        {
            id: nowPlaying
        }
    ]
}