//
//  SecondViewController.swift
//  TempTest
//
//  Created by - on 2017/01/06.
//  Copyright © 2017 Danth. All rights reserved.
//

import UIKit

class SecondViewController: UIViewController {
    @IBOutlet weak var scrollView: UIScrollView!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        scrollView.contentInset = UIEdgeInsetsMake(0, 0, 100, 0)
        
        
        
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

