//
//  ViewController.swift
//  MedSync3.0
//
//  Created by - on 2017/01/04.
//  Copyright © 2017 Danth. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    @IBOutlet weak var Button0: UIButton!
    @IBOutlet weak var Button1: UIButton!
    @IBOutlet weak var Button2: UIButton!
    @IBOutlet weak var Button3: UIButton!
    @IBOutlet weak var Button4: UIButton!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        let imageView = UIImageView(frame: CGRect(x: 0, y: 0, width: 40, height: 40))
        
        imageView.contentMode = .scaleAspectFit
        
        let image = UIImage(named: "MedSyncLogo.png")
        imageView.image = image
        
        navigationItem.titleView = imageView
        
        

       
        
        Button0.imageView?.contentMode = UIViewContentMode.scaleAspectFill
        Button1.imageView?.contentMode = UIViewContentMode.scaleAspectFill
        Button2.imageView?.contentMode = UIViewContentMode.scaleAspectFill
        Button3.imageView?.contentMode = UIViewContentMode.scaleAspectFill
        Button4.imageView?.contentMode = UIViewContentMode.scaleAspectFit



        
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

