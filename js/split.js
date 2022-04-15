const fs = require('fs')

// fetch('./sc.json')
//     .then(d => d.json())
//     .then(d => {
//         // console.log(d)
//         let features = d.features;
//         for(let i = 0 ; i < features.length ; ++ i){
//             let f = features[i];
//             let geo = f.geometry.coordinates[0];
//             let str = JSON.stringify(geo);
//             download(`aaaa${i}.json`,str);
//             // console.log(i)
//         }
//     })

fs.readFile('./sc.json' , (err, d ) => {
    let geojson = JSON.parse(d.toString());
    let features = geojson.features;

    for(let i = 0 ; i < features.length ; ++ i){
        let f = features[i];
        let geo = f.geometry.coordinates[0];
        let str = JSON.stringify(geo);
        fs.writeFile('map/' + i + '.json',str , (err) => {
            console.log(err)
        })
    }
})