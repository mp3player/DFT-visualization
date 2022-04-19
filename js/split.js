const fs = require('fs')

fs.readFile('./china.json' , (err, d ) => {
    let geojson = JSON.parse(d.toString());
    let features = geojson.features;

    for(let i = 0 ; i < features.length ; ++ i){
        let f = features[i];
        let geo = f.geometry.coordinates[0];
        let part = []
        for(let j = 0 ; j < geo.length ; j += 2){
            part.push(geo[j]);
        }
        // part.push(geo[0]);
        
        let str = JSON.stringify(part);
        fs.writeFile('map/' + i + '.json',str , (err) => {
            console.log(err)
        })
    }
})