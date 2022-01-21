from behave import *

import os.path
import subprocess



@given('we have a main application')
def step_impl(context):
    assert os.path.isfile("../build/a.out")

@when('we run main application')
def step_impl(context):
    return_code = subprocess.run(["../build/a.out"], capture_output=True).returncode
    assert return_code == 0

@then('the number 4 shall be returned as the number of rectangle corners')
def step_impl(context):
    return_code = subprocess.run(["../build/a.out"], capture_output=True).stdout
    assert return_code == b"4\n"