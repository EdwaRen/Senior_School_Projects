//
//  FirstViewController.swift
//  MedSync2.0
//
//  Created by - on 2017/01/04.
//  Copyright © 2017 Danth. All rights reserved.
//

import UIKit

class FirstViewController: UIViewController {

  
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        _ = self.navigationController?.navigationBar
        
        let imageView = UIImageView(frame: CGRect(x: 0, y: 0, width: 40, height: 40))
        
        imageView.contentMode = .scaleAspectFit
        
        let image = UIImage(named: "MedSyncLogo.png")
        imageView.image = image
        
        navigationItem.titleView = imageView

        
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBOutlet weak var Services: UIButton!
    @IBAction func Services(_ sender: AnyObject) {
        self.tabBarController?.selectedIndex = 2
    }
    @IBAction func Portfolio(_ sender: AnyObject) {
        self.tabBarController?.selectedIndex = 3
        
        let imageView = UIImageView(frame: CGRect(x: 0, y: 0, width: 40, height: 40))
        
        imageView.contentMode = .scaleAspectFit
        
        let image = UIImage(named: "Flowers.jpg")
        imageView.image = image
        
        navigationItem.titleView = imageView
    }
    @IBAction func About(_ sender: AnyObject) {
        self.tabBarController?.selectedIndex = 2
    }
    @IBAction func Contact(_ sender: AnyObject) {
        self.tabBarController?.selectedIndex = 4
    }
    @IBAction func Social(_ sender: AnyObject) {
    }

}

