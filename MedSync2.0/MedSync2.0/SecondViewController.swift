//
//  SecondViewController.swift
//  MedSync2.0
//
//  Created by - on 2017/01/04.
//  Copyright © 2017 Danth. All rights reserved.
//

import UIKit

class SecondViewController: UIViewController {

    override func viewDidLoad() {
        
        let imageView = UIImageView(frame: CGRect(x: 0, y: 0, width: 40, height: 40))
        
        imageView.contentMode = .scaleAspectFit
        
        let image = UIImage(named: "MedSyncLogo.png")
        imageView.image = image
        
        navigationItem.titleView = imageView

        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

